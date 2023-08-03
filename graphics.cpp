#include "graphics.h"

#include <QDir>

graphics::graphics()
{

}

QList<QString> graphics::readGraphics()
{
    graphicFiles_.clear();
    QDir graphicsDir(":/graphics/" + graphicsDirectory_ + "/");
    QStringList fileNames = graphicsDir.entryList(QDir::Files);
    for (const QString& fileName : fileNames) {
        graphicFiles_.append(fileName);
    }
    emit sendGraphicFiles(graphicFiles_);
}

void graphics::setCurrentGraphicsDirectory(int graphicsType)
{
    switch (graphicsType) {
    case 0:
        graphicsDirectory_ = "disney"; break;
    case 1:
        graphicsDirectory_ = "frozen"; break;
    case 2:
        graphicsDirectory_ = "pony"; break;
    case 3:
        graphicsDirectory_ = "unicorn"; break;
    case 4:
        graphicsDirectory_ = "dragon"; break;
    default:
        break;
    }
}
