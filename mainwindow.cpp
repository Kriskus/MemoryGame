#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "graphics.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Graphics graphics;
    graphics.setCurrentGraphicsDirectory(0);

    setColumns(4);
    setRows(4);

    createBoardGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test(Card * card)
{
    qDebug() << QString::number(card->getNumber());
}

void MainWindow::createBoardGame()
{
    Deck* deck = new Deck(rows_ * columns_);

    QList<Card*> cardList = deck->getdeck();

    for (int i = 0; i < cardList.size(); ++i)
    {
        Card* card = cardList.at(i);
        connect(card, &Card::clicked, this, &MainWindow::test);
        ui->gameLayout->addWidget(card, i / 4, i % 4);
        cards_.push_back(card);
    }
}

void MainWindow::clearBoardGame()
{
    for(auto element: cards_) {
        ui->gameLayout->removeWidget(element);
        element->deleteLater();
    }
    cards_.clear();
}

void MainWindow::newGame()
{
    if(checkOfGameEnd()) {
        endGame();
    }
    createBoardGame();
}

void MainWindow::endGame()
{
    clearBoardGame();
}

bool MainWindow::checkOfGameEnd()
{
    for(auto card: cards_) {
        if(card->isEnabled()) {
            return false;
        }
    }
    return true;
}

void MainWindow::setColumns(int amount)
{
    ui->gameLayout->setColumnStretch(amount, 1);
    columns_ = amount;
}

void MainWindow::setRows(int amount)
{
    ui->gameLayout->setRowStretch(amount, 1);
    rows_ = amount;
}

