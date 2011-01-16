#include "review.h"

Review::Review(QObject *parent) :
    QObject(parent)
{
}

void Review::setId(QString id)
{
    this->id = id;
}

void Review::setrating(int rating)
{
    this->rating = rating;
}

void Review::setRatingImageUrl(QString url)
{
    this->rating_image_url =url;
}

void Review::setRatingImageUrlSmall(QString url)
{
    this->rating_image_url_small = url;
}

void Review::setTextExcerpt(QString excerpt)
{
    this->text_excerpt = excerpt;
}

void Review::setUrl(QString url)
{
    this->url = url;
}

void Review::setUsername(QString username)
{
    this->username = username;
}

void Review::setUserPhotoUrl(QString url)
{
    this->user_photo_url = url;
}

void Review::setUserPhotoUrlSmall(QString url)
{
    this->user_photo_url_small = url;
}

void Review::setMobileUri(QString uri)
{
    this->mobile_uri = uri;
}

void Review::setUserUrl(QString url)
{
    this->user_url = url;
}

QString Review::getId()
{
    return id;
}

int Review::getRating()
{
    return rating;
}

QString Review::getRatingImageUrl()
{
    return rating_image_url;
}

QString Review::getRatingImageUrlSmall()
{
    return rating_image_url_small;
}

QString Review::getTextExcerpt()
{
    return text_excerpt;
}

QString Review::getUsername()
{
    return username;
}

QString Review::getUrl()
{
    return url;
}

QString Review::getUserPhotoUrl()
{
    return user_photo_url;
}

QString Review::getUserPhotoUrlSmall()
{
    return user_photo_url_small;
}

QString Review::getMobileUri()
{
    return mobile_uri;
}

QString Review::getUserUrl()
{
    return user_url;
}
