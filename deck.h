#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <QList>
#include <QObject>
#include <QSharedPointer>

class Deck : public QObject
{
    Q_OBJECT
public:
    explicit Deck(int deckSize);

public slots:
    QList<Card*> getdeck();

private:
    QList<Card*> deck_{};
    QList<QString> graphicFiles_{};
    int cardNr{0};
    int deckSize_{0};
    QPixmap coveredImage_{};
    QPixmap uncoveredImage_{};

private slots:
    void createDeck();
    QList<QString> shuffleDeck(QList<QString> data);
    void prepareGraphics();

signals:

};

#endif // DECK_H
