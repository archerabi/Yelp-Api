#-------------------------------------------------
#
# Project created by QtCreator 2011-01-12T13:39:41
#
#-------------------------------------------------

QT       += core gui network script

TARGET = Yelp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    api/yelpapi.cpp \
    api/yelpapiresponse.cpp \
    api/business.cpp \
    api/review.cpp

HEADERS  += mainwindow.h \
    api/yelpapi.h \
    api/yelpapiresponse.h \
    api/YelpUrls.h \
    api/business.h \
    api/review.h

FORMS    += mainwindow.ui
