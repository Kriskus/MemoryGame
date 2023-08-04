#include "graphics.h"

#include <QDir>

Graphics::Graphics()
{

}

QList<QString> Graphics::readGraphics()
{
    graphicFiles_.clear();
    QDir graphicsDir(graphicsDirectory_);
    QStringList fileNames = graphicsDir.entryList(QDir::Files);
    for (const QString& fileName : fileNames) {
        graphicFiles_.append(fileName);
    }
    return graphicFiles_;
}

void Graphics::setCurrentGraphicsDirectory(int graphicsType)
{
    switch (graphicsType) {
    case 0:
        graphicsDirectory_ = ":/graphics/disney/"; break;
    case 1:
        graphicsDirectory_ = ":/graphics/frozen/"; break;
    case 2:
        graphicsDirectory_ = ":/graphics/pony/"; break;
    case 3:
        graphicsDirectory_ = ":/graphics/unicorn/"; break;
    case 4:
        graphicsDirectory_ = ":/graphics/dragon/"; break;
    default:
        break;
    }
}
