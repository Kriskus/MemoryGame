#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QList>
#include <QObject>
#include <qstring.h>

class graphics
{
    Q_OBJECT
public:
    graphics();

public slots:
    QList<QString> readGraphics();
    void setCurrentGraphicsDirectory(int graphicsType);

private:
    QString graphicsDirectory_{};
    QList<QString> graphicFiles_{};

signals:
    void sendGraphicFiles(QList<QString>);
};

#endif // GRAPHICS_H
