#ifndef REVIEW_H
#define REVIEW_H

#include <QObject>

class Review : public QObject
{
    Q_OBJECT
    public:
        explicit Review(QObject *parent = 0);

        void setId(QString id);
        void setrating(int);
        void setRatingImageUrl(QString url);
        void setRatingImageUrlSmall(QString url);
        void setTextExcerpt(QString excerpt);
        void setUrl(QString url);
        void setUsername(QString username);
        void setUserPhotoUrl(QString userPhotoUrl);
        void setUserPhotoUrlSmall(QString userPhotoUrlSmall);
        void setMobileUri(QString uri);
        void setUserUrl(QString url);

        QString getId();
        int getRating();
        QString getRatingImageUrl();
        QString getRatingImageUrlSmall();
        QString getTextExcerpt();
        QString getUsername();
        QString getUrl();
        QString getUserPhotoUrl();
        QString getUserPhotoUrlSmall();
        QString getMobileUri();
        QString getUserUrl();
    signals:

    public slots:

    private:
        QString id;
        int rating;
        QString rating_image_url;
        QString rating_image_url_small;
        QString text_excerpt;
        QString url;
        QString username;
        QString user_photo_url;
        QString user_photo_url_small;
        QString mobile_uri;
        QString user_url;

};

#endif // REVIEW_H
