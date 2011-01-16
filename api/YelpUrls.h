#ifndef YELPURLS_H
#define YELPURLS_H
#include <QString>

QString YURL_SearchByPosition = "http://api.yelp.com/business_review_search?term=%1&lat=%2&long=%3&radius=%4&limit=%5&ywsid=%6";
QString YURL_SearchByLocation = "http://api.yelp.com/business_review_search?term=%1&location=%2&limit=%3&ywsid=%4";
#endif // YELPURLS_H
