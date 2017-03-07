#include "FilterableImage.h"

#include <QPainter>

FilterableImage::FilterableImage(QQuickItem *parent) : QQuickPaintedItem(parent)
{

}

float FilterableImage::getLevel() const
{
    return m_level;
}

void FilterableImage::setLevel(float level)
{
    if (m_level == level)
            return;

    m_level = level;
    emit levelChanged(level);
    update();
}

#include <QDebug>

void FilterableImage::loadFromFile(const QUrl& fileUri)
{
    qDebug() << "Loading from" << fileUri;
}

void FilterableImage::saveToFile(const QUrl& fileUri)
{
    qDebug() << "Saving to" << fileUri;
}

void FilterableImage::paint(QPainter * painter)
{
    const auto value = 255 * m_level;
    painter->fillRect(painter->viewport(), qRgb(value, value, value) );
}
