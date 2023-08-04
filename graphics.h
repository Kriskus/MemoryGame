#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QList>
#include <QObject>
#include <qstring.h>

class Graphics : public QObject
{
    Q_OBJECT
public:
    Graphics();

public slots:
    QList<QString> readGraphics();
    void setCurrentGraphicsDirectory(int graphicsType);

private:
    QString graphicsDirectory_{};
    QList<QString> graphicFiles_{};

};

#endif // GRAPHICS_H
