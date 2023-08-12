#ifndef SETTINGS_H
#define SETTINGS_H

#include <QCloseEvent>
#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private:
    Ui::Settings *ui;
    void closeEvent(QCloseEvent *event);

private slots:
    void setGraphics(int type);

signals:
    void graphicsType(int);
    void closeWindow();
};

#endif // SETTINGS_H
