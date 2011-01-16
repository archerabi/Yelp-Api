#include "yelpapi.h"
#include "yelpapiresponse.h"
#include "api/YelpUrls.h"
#include <QDebug>
#include "business.h"
#include <QScriptValueIterator>

const int limit=20;
YelpApi::YelpApi(QObject *parent) :
    QObject(parent)
{
    netManager = new QNetworkAccessManager(this);
    connect(netManager,SIGNAL(finished(QNetworkReply*)),this,SLOT(responseRecieved(QNetworkReply*)));
    engine = new QScriptEngine(this);
}

void YelpApi::setApikey(QString key)
{
    apiKey = key;
}

void YelpApi::callMethod(QString url,int callType)
{
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply* reply = netManager->get(request);
    replyTypeMap.insert((int)reply,callType);
}

void YelpApi::responseRecieved(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QString responseString=reply->readAll();
        QScriptValue val = engine->evaluate("(" + responseString +")");

        switch(replyTypeMap.value((int)reply))
        {
            case SearchByPointAndRadius:
            case SearchByLocation:
                QList<Business*>* list = getBusinessesFromResponse(val);
                emit recievedBusinesses(list);
                deleteBusinessList(list);
            break;
        }
        replyTypeMap.remove((int)reply);

    }
}

void YelpApi::searchByPosition(double latitude,double longitude,int radiusInMiles,QString term)
{
    QString url ;
    url = QString(YURL_SearchByPosition)
            .arg(term)
            .arg(QString().setNum(latitude))
            .arg(QString().setNum(longitude))
            .arg(QString().setNum(radiusInMiles))
            .arg(QString().setNum(limit))
            .arg(apiKey);
    qDebug() << url;
    callMethod(url,SearchByPointAndRadius);
}

void YelpApi::searchByLocation(QString location,QString term)
{
    QString url ;
    url = QString(YURL_SearchByLocation)
          .arg(term)
          .arg(location)
          .arg(limit)
          .arg(apiKey);
    qDebug() << url;
    callMethod(url,SearchByLocation);
}

QList<Business*>* YelpApi::getBusinessesFromResponse(QScriptValue val)
{
    QList<Business*>* list = new QList<Business*>();
    QScriptValue businesses = val.property("businesses");
    if(businesses.isValid() && businesses.isArray())
    {
        QScriptValueIterator it(businesses);
         while (it.hasNext()) {
             it.next();
             list->append( createBusiness(it.value()) );
         }
    }
    return list;
}

Business* YelpApi::createBusiness(QScriptValue val)
{
    Business* b = new Business(this);
    b->setaddress(val.property("address1").toString(),
                  val.property("address2").toString(),
                  val.property("address3").toString());
    b->setCity(val.property("city").toString());;
    b->setCountry(val.property("country").toString());
    b->setDistance(val.property("distance").toString().toDouble());
    b->setId(val.property("id").toString());
    b->setLatitude(val.property("latitude").toString().toDouble());
    b->setLongitude(val.property("longitude").toString().toDouble());
    b->setName(val.property("name").toString());
    b->setRating(val.property("avg_rating").toString().toFloat());
    b->setState(val.property("state").toString());
    b->setZip(val.property("zip").toString());
    return b;
}

void YelpApi::deleteBusinessList(QList<Business*>* list)
{
    while (!list->isEmpty())
        delete list->takeFirst();
}
