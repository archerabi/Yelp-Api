#include "business.h"

Business::Business(QObject *parent) :
    QObject(parent)
{
}

Business::Business(Business* b)
{
    this->address1 = b->address1;
    this->address2 = b->address2;
    this->address3 = b->address3;

    this->city = b->city;
    this->state = b->state;
    this->country = b->country;
    this->distance = b->distance;

    this->name = b->name;
    this->id = b->id;

    this->zip = b->zip;
    this->is_closed = b->is_closed;

    this->latitude = b->latitude;
    this->longitude = b->longitude;

    this->avgRating = b->avgRating;
}

void Business::setaddress(QString address1,QString address2,QString address3)
{
    this->address1 = address1;
    this->address2 = address2;
    this->address3 = address3;
}

void Business::setCity(QString city)
{
    this->city = city;
}

void Business::setState(QString state)
{
    this->state = state;
}

void Business::setCountry(QString country)
{
    this->country = country;
}

void Business::setZip(QString zip)
{
    this->zip = zip;
}

void Business::setName(QString name)
{
    this->name = name;
}

void Business::setId(QString id)
{
    this->id = id;
}

void Business::setLatitude(double lat)
{
    this->latitude = lat;
}

void Business::setLongitude(double longitude)
{
    this->longitude = longitude;
}

void Business::setDistance(double distance)
{
    this->distance = distance;
}

void Business::setRating(float rating)
{
    this->avgRating = rating;
}

QString Business::getName()
{
    return name;
}

QString Business::getAddress()
{
    return address1 ;
}

QString Business::getId()
{
    return id;
}

float Business::getRating()
{
    return avgRating;
}

double Business::getDistance()
{
    return distance;
}
