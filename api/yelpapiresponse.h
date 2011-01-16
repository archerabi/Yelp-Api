#ifndef YELPAPIRESPONSE_H
#define YELPAPIRESPONSE_H

#include <QObject>

class YelpApiResponse : public QObject
{
    Q_OBJECT
    public:
        explicit YelpApiResponse(QObject *parent = 0);

    signals:

    public slots:
    private:

};

#endif // YELPAPIRESPONSE_H
