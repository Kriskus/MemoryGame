#include "graphics.h"

#include <QDir>

Graphics::Graphics()
{
    setCurrentGraphicsDirectory(3);
}

QList<QString> Graphics::readGraphics()
{
    graphicFiles_.clear();
    QDir graphicsDir(graphicsDirectory_);
    QStringList fileNames = graphicsDir.entryList(QDir::Files);
    for (const QString& fileName : fileNames) {
        graphicFiles_.append(graphicsDirectory_ + fileName);
    }
    return graphicFiles_;
}

void Graphics::setCurrentGraphicsDirectory(int graphicsType)
{
    switch (graphicsType) {
    case 0:
        graphicsDirectory_ = ":/disney/graphics/disney/"; break;
    case 1:
        graphicsDirectory_ = ":/frozen/graphics/frozen/"; break;
    case 2:
        graphicsDirectory_ = ":/pony/graphics/pony/"; break;
    case 3:
        graphicsDirectory_ = ":/pawpatrol/graphics/pawpatrol/"; break;
    default:
        break;
    }
}
