#include "card.h"

Card::Card(int cardNr, const QPixmap &coveredImage, const QPixmap &uncoveredImage, QSize cardSize)
    : coveredImage_(coveredImage)
    , uncoveredImage_(uncoveredImage)
{
    setFixedSize(cardSize);
    setObjectName(QString::number(cardNr));
    setStyleSheet("");
    setAlignment(Qt::AlignCenter);

    setCardSize(cardSize.width(), cardSize.height());

    coverCard();
}

void Card::setCardSize(int width, int height)
{
    setFixedSize(width, height);
}

void Card::coverCard()
{
    setPixmap(coveredImage_.scaled(size(), Qt::IgnoreAspectRatio));
}

void Card::uncoverCard()
{
    setPixmap(uncoveredImage_.scaled(size(), Qt::IgnoreAspectRatio));
}

void Card::deactivateCard()
{
    clear();
    setStyleSheet("");
    setFrameStyle(0);
    setDisabled(1);
}

QImage Card::getImage()
{
    return pixmap(Qt::ReturnByValue).toImage();
}

int Card::getNumber()
{
    return objectName().toInt();
}

void Card::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit clicked(this);
}
