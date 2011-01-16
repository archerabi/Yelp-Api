#ifndef YELPAPI_H
#define YELPAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMap>
#include <QScriptEngine>

class YelpApiResponse;
class Business;


class YelpApi : public QObject
{
    Q_OBJECT
    public:
        explicit YelpApi(QObject *parent = 0);

        enum MethodTypes{
            SearchByPointAndRadius=1,
            SearchByLocation
        };

        void callMethod(QString url,int callType);
        void searchByPosition(double latitude,double longitude,int radiusInMiles=10,QString term="");
        void searchByLocation(QString location,QString term="");

        void setApikey(QString key);

        QList<Business*>* getBusinessesFromResponse(QScriptValue response);
        Business* createBusiness(QScriptValue val);
    signals:
        void yelpResponseRecieved(YelpApiResponse* response,MethodTypes type);
        void recievedBusinesses(QList<Business*>* bList);
    private slots:
        void deleteBusinessList(QList<Business*>* list);
        void responseRecieved(QNetworkReply*);
    private:
        QMap<int,int> replyTypeMap;
        QNetworkAccessManager* netManager;
        QString apiKey;
        QScriptEngine* engine;
};

#endif // YELPAPI_H
