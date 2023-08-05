#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "deck.h"

#include <QMainWindow>

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

    int columns_{0};
    int rows_{0};

    QList<Card*> cards_;
    QList<Card*> selectedCards_;

private slots:
    void createBoardGame();
    void clearBoardGame();

    void newGame();
    void endGame();

    bool checkOfGameEnd();

    void setColumns(int amount);
    void setRows(int amount);
};
#endif // MAINWINDOW_H
