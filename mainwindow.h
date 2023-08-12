#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "deck.h"
#include "settings.h"

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void test(Card *card);

private:
    Ui::MainWindow *ui;
    QTimer* timer_{};

    int columns_{0};
    int rows_{0};
    QSize cardSize_{0,0};

    int moves_{0};
    int seconds_{0};
    int minutes_{0};

    bool isFirstClick_{true};
    bool isCheckingCards_{false};
    bool isHandlingClick_{false};

    QList<Card*> cards_;
    QList<Card*> selectedCards_;

    int graphicsType_{1};

private slots:
    void createBoardGame();
    void clearBoardGame();

    void endGame();

    void setClickedCard(QObject *obj);
    bool checkCards(Card *labelOne, Card *labelTwo);
    void checkSelectedCards();

    void updateTime();
    void updateMoves();

    void checkOfGameEnd();

    void startTimer();
    void setColumns(int amount);
    void setRows(int amount);

    void openSettings();

signals:
    void endTimer();
};
#endif // MAINWINDOW_H
