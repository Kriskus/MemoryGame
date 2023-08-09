#include "deck.h"

#include <random>
#include <algorithm>

Deck::Deck(int deckSize, QSize cardSize, int graphicsType)
    : deckSize_(deckSize)
    , cardSize_(cardSize)
{
    graphics_ = new Graphics();
    graphics_->setCurrentGraphicsDirectory(graphicsType);

    setGraphicsType(graphicsType);
    coveredImage_.load(":/covered/graphics/covered/covered.png");

    prepareGraphics();
    createDeck();    
}

void Deck::createDeck()
{
    for(cardNr = 0; cardNr < deckSize_; cardNr++) {
        uncoveredImage_.load(cardImages_[cardNr]);
        Card* card = new Card(cardNr, coveredImage_, uncoveredImage_, cardSize_);
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

void Deck::setGraphicsType(int graphicsType)
{
    graphicFiles_ = graphics_->readGraphics();
}

void Deck::prepareGraphics()
{
    cardImages_ = shuffleDeck(graphicFiles_);
    cardImages_.resize(deckSize_/2);
    cardImages_.append(cardImages_);
    cardImages_ = shuffleDeck(cardImages_);
}
