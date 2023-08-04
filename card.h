#ifndef CARD_H
#define CARD_H

#include <QImage>
#include <QLabel>
#include <QObject>
#include <QPixmap>

class Card : public QLabel
{
    Q_OBJECT
public:
    Card(int cardNr, const QPixmap &coveredImage, const QPixmap &uncoveredImage);

public slots:
    void setCardSize(int width, int height);

    void coverCard();
    void uncoverCard();

    void deactivateCard();

    QImage getImage();
    int getNumber();

private:
    QPixmap coveredImage_{};
    QPixmap uncoveredImage_{};

signals:
    void clicked(Card* card);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // CARD_H
