#include "qrcodeimage.h"
#include "qrcodegen/qrcodegen.hpp"
#include <QImage>
#include <QPainter>
#include <QDebug>

QPixmap qrCodePixmap(const QString &strText, int nBoxPx, int *pnVersion, int *pnScale)
{
    try
    {
        qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(strText.toUtf8().constData(), qrcodegen::QrCode::Ecc::MEDIUM);
        const int nQuiet = 4;
        int nCount = qr.getSize() + nQuiet*2;
        int nScale = qMax(1, nBoxPx / nCount);

        QImage img(nCount*nScale, nCount*nScale, QImage::Format_RGB32);
        img.fill(Qt::white);
        QPainter painter(&img);
        for(int y=0; y<qr.getSize(); y++)
            for(int x=0; x<qr.getSize(); x++)
                if(qr.getModule(x,y))
                    painter.fillRect((x+nQuiet)*nScale, (y+nQuiet)*nScale, nScale, nScale, Qt::black);
        painter.end();

        if(pnVersion)
            *pnVersion = qr.getVersion();
        if(pnScale)
            *pnScale = nScale;
        return QPixmap::fromImage(img);
    }
    catch(const std::exception &e)
    {
        qDebug()<<"[fail] QR encode: "<<e.what();
        return QPixmap();
    }
}
