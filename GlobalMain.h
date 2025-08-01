#ifndef GLOBALMAIN_H
#define GLOBALMAIN_H

//=======================
// Define Constants
//=======================

#define DEVICE true
#define IMAGE_FILE_CHECK false
#define GLUCOSE_LOW_PLUS 5
#define GLUCOSE_HIGH_MINUS -30
#define WINDOW_CALI false
#define NEW_PASSWORD true
#define FONT_DEBUG false

#define DEBUG_FLAG_BATTERY false
#if DEBUG_FLAG_BATTERY
    #define DEBUG_BAT(msg) qDebug() << msg
#else
    #define DEBUG_BAT(msg) do{} while(0)
#endif

//=======================
// Qt Library
//=======================

#include <QScreen>
#include <QSplashScreen>
#include <QTimer>
#include <QThread>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QPoint>
#include <QMouseEvent>
#include <QLabel>
#include <QList>
#include <QRandomGenerator>
#include <QStackedWidget>
#include <QDateTime>
#include <QLocale>
#include <QHash>
#include <QPair>
#include <QApplication>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>

//=======================
// guiapi Library
//=======================

#include <guiapi/gapi.h>
#include <guiapi/guiapi.h>
#include <guiapi/vtipc.h>

//=======================
// custom Library
//=======================


#endif // GLOBALMAIN_H
