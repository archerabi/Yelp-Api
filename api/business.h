#ifndef BUSINESS_H
#define BUSINESS_H

#include <QObject>

class Business : public QObject
{
    Q_OBJECT
    public:
        explicit Business(QObject *parent = 0);
        Business(Business* b);

        void setaddress(QString address1,QString address2="",QString address3="");
        void setCity(QString city);
        void setState(QString state);
        void setCountry(QString country);
        void setZip(QString zip);

        void setName(QString name);
        void setId(QString id);

        void setLatitude(double lat);
        void setLongitude(double longitude);
        void setDistance(double distance);
        void setRating(float rating);

        QString getName();
        QString getAddress();
        QString getId();
        float getRating();
        double getDistance();

    signals:

    public slots:
    private:
        QString address1;
        QString address2;
        QString address3;
        QString city;
        QString state;
        QString stateCode;
        QString country;
        QString countryCode;
        QString zip;

        QString name;
        QString id;


        bool is_closed;

        double latitude;
        double longitude;

        double distance;
        float avgRating;
};

#endif // BUSINESS_H
