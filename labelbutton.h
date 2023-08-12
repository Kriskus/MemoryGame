#ifndef LABELBUTTON_H
#define LABELBUTTON_H

#include <QLabel>
#include <QObject>

class LabelButton : public QLabel
{
    Q_OBJECT
public:
    LabelButton(QString name, QString pixmap);

signals:
    void clicked(int);

protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // LABELBUTTON_H
