#ifndef QRCODEIMAGE_H
#define QRCODEIMAGE_H

#include <QPixmap>
#include <QString>

//hrkim 20261026 QR 그림 만들기 — 어느 화면에서든 같은 모양으로 (ECC M, 여백 4칸, 흰 바탕, 칸 크기는 nBoxPx 안에서 가장 크게)
// 팬텀 해제 결과 코드 QR 에서 떼어 냄: 결과 QR 을 다른 자리(해제 앞·히든 메뉴 등)로 옮길 때 그대로 쓰게 (XW-0446, Hr 2026-10-26 "모듈화")
// 실패하면 null pixmap
QPixmap qrCodePixmap(const QString &strText, int nBoxPx, int *pnVersion = nullptr, int *pnScale = nullptr);

#endif // QRCODEIMAGE_H
