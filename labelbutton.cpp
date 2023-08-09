#include "labelbutton.h"

LabelButton::LabelButton(QString name, QString pixmap)
{
    setFixedSize(300,300);
    QPixmap image;
    image.load(pixmap);
    setPixmap(image.scaled(300,300, Qt::IgnoreAspectRatio));
    setObjectName(name);
}

void LabelButton::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked(objectName().toInt());
}
