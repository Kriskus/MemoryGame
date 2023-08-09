#include "labelbutton.h"

LabelButton::LabelButton(QString name, QString pixmap)
{
    setFixedSize(200,200);
    QPixmap image;
    image.load(pixmap);
    setObjectName(name);
}

void LabelButton::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked(objectName().toInt());
}
