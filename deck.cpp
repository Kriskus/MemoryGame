#include "deck.h"
#include "graphics.h"

#include <random>
#include <algorithm>

Deck::Deck(int deckSize)
    : deckSize_(deckSize)
{
    Graphics graphics;
    graphicFiles_ = graphics.readGraphics();

    coveredImage_.load(":/covered/graphics/covered/covered.png");

    prepareGraphics();
    createDeck();    
}

void Deck::createDeck()
{
    for(cardNr = 0; cardNr < deckSize_; cardNr++) {
        uncoveredImage_.load(cardImages_[cardNr]);
        Card* card = new Card(cardNr, coveredImage_, uncoveredImage_);
        connect(card, &Card::clicked, card, &Card::uncoverCard);
        deck_.push_back(card);
    }
}

QList<QString> Deck::shuffleDeck(QList<QString> data)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(data.begin(), data.end(), gen);
    return data;
}

QList<Card*> Deck::getdeck()
{
    return deck_;
}

void Deck::prepareGraphics()
{
    cardImages_ = shuffleDeck(graphicFiles_);
    cardImages_.resize(deckSize_/2);
    cardImages_.append(cardImages_);
    cardImages_ = shuffleDeck(cardImages_);
}
