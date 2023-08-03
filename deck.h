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

    void createDeck();
    void shuffleDeck();
    QList<QSharedPointer<Card>> getdeck();

    void prepareGraphics();

signals:

};

#endif // DECK_H
