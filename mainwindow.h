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

private slots:
    setColumns(int amount);
    setRows(int amount);
};
#endif // MAINWINDOW_H
