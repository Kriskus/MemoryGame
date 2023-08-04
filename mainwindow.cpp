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

    ui->gameLayout->setColumnStretch(4, 1);
    ui->gameLayout->setRowStretch(4, 1);

    Deck* deck = new Deck(16);

    QList<Card*> cardList = deck->getdeck();

    for (int i = 0; i < cardList.size(); ++i)
    {
        Card* card = cardList.at(i);
        connect(card, &Card::clicked, this, &MainWindow::test);
        ui->gameLayout->addWidget(card, i / 4, i % 4);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test(Card * card)
{
    qDebug() << QString::number(card->getNumber());
}

MainWindow::setColumns(int amount)
{
    ui->gameLayout->setColumnStretch(amount, 1);
}

MainWindow::setRows(int amount)
{
    ui->gameLayout->setRowStretch(amount, 1);
}

