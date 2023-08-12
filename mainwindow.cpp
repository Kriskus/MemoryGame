#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "graphics.h"

#include <QScreen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::openSettings);

    setColumns(4);
    setRows(4);

    QRect screenGeometry = QGuiApplication::primaryScreen()->availableGeometry();

    cardSize_.setWidth(screenGeometry.width() * 0.6 / columns_);
    cardSize_.setHeight(screenGeometry.height() * 0.9 / rows_);

    Graphics graphics;
    graphics.setCurrentGraphicsDirectory(4);

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
    Deck* deck = new Deck(rows_ * columns_, cardSize_, graphicsType_);
    connect(this, &MainWindow::endTimer, deck, &Deck::deleteLater);
    QList<Card*> cardList = deck->getdeck();
    for (int i = 0; i < cardList.size(); ++i)
    {
        Card* card = cardList.at(i);
        connect(card, &Card::clicked, this, &MainWindow::setClickedCard);
        int row = i / columns_;
        int col = i % columns_;
        ui->gameLayout->addWidget(card, row, col);
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

void MainWindow::endGame()
{
    emit endTimer();
    isFirstClick_ = true;
    moves_ = 0;
    clearBoardGame();
    createBoardGame();
}

void MainWindow::setClickedCard(QObject *obj)
{
    if (isFirstClick_) {
        startTimer();
        isFirstClick_ = false;
    }

    if (selectedCards_.size() < 2) {
        Card *card = qobject_cast<Card*>(obj);
        if (card) {
            card->uncoverCard();
            card->setStyleSheet("background-color: green;");
            selectedCards_.append(card);
            updateMoves();
            if (selectedCards_.size() == 2) {
                checkSelectedCards();
            }
        }
    }
}

bool MainWindow::checkCards(Card *labelOne, Card *labelTwo)
{
    if(labelOne->getImage() == labelTwo->getImage() && labelOne->getNumber() != labelTwo->getNumber()) {
        return true;
    } else {
        return false;
    }
}

void MainWindow::checkSelectedCards()
{
    if (selectedCards_.size() == 2) {
        if (checkCards(selectedCards_.at(0), selectedCards_.at(1))) {
            QTimer::singleShot(250, [this] () {
                selectedCards_.at(0)->deactivateCard();
                selectedCards_.at(1)->deactivateCard();
                selectedCards_.clear();
                checkOfGameEnd();
            });
        } else {
            QTimer::singleShot(1000, [this] () {
                selectedCards_.at(0)->coverCard();
                selectedCards_.at(1)->coverCard();
                selectedCards_.clear();
            });
        }
        isCheckingCards_ = false;
    }
}

void MainWindow::updateTime()
{
    seconds_++;
    if(seconds_ == 60) {
        minutes_++;
        seconds_ = 0;
    }
    if(seconds_ < 10) {
        ui->labelTime->setText(QString::number(minutes_) + ":0" + QString::number(seconds_));
    } else {
        ui->labelTime->setText(QString::number(minutes_) + ":" + QString::number(seconds_));
    }
}

void MainWindow::updateMoves()
{
    ui->labelMove->setText(QString::number(++moves_));
}

void MainWindow::checkOfGameEnd()
{
    for(auto card: cards_) {
        if(card->isEnabled()) {
            return;
        }
    }
    endGame();
}

void MainWindow::startTimer()
{
    seconds_ = 0;
    minutes_ = 0;
    timer_ = new QTimer(this);
    connect(timer_, &QTimer::timeout, this, &MainWindow::updateTime);
    connect(this, &MainWindow::endTimer, timer_, &QTimer::deleteLater);
    timer_->start(1000);
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

void MainWindow::openSettings()
{
    Settings* settingWindow = new Settings();
    connect(settingWindow, &Settings::graphicsType, [this](int type) {
        graphicsType_ = type;
        endGame();
    });
    connect(settingWindow, &Settings::closeWindow, settingWindow, &Settings::deleteLater);
    settingWindow->show();
}

