#include "card.h"

Card::Card(int cardNr, const QPixmap &coveredImage, const QPixmap &uncoveredImage)
    : coveredImage_(coveredImage)
    , uncoveredImage_(uncoveredImage)
{
    setObjectName(QString::number(cardNr));
    setStyleSheet("");
    setFrameStyle(0);
    setAlignment(Qt::AlignCenter);

    coverCard();
}

void Card::setCardSize(int width, int height)
{
    setFixedSize(width, height);
}

void Card::coverCard()
{
    setPixmap(coveredImage_.scaled(size(), Qt::KeepAspectRatio));
}

void Card::uncoverCard()
{
    setPixmap(uncoveredImage_.scaled(size(), Qt::KeepAspectRatio));
}

void Card::deactivateCard()
{
    clear();
    setStyleSheet("");
    setFrameStyle(0);
}

QImage Card::getImage()
{
    return pixmap(Qt::ReturnByValue).toImage();
}

int Card::getNumber()
{
    return objectName().toInt();
}
