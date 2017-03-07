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
    m_image = QImage( fileUri.toLocalFile() );

    if (m_image.isNull()) {
        qDebug() << "Loading image from" << fileUri << " failed!";
    }

    update();
}

void FilterableImage::saveToFile(const QUrl& fileUri)
{
    if (!m_image.isNull()) {
        qDebug() << "Saving to" << fileUri;
        m_image.save(fileUri.toLocalFile());
    }
}

void FilterableImage::paint(QPainter * painter)
{
    if (!m_image.isNull()) {
        painter->drawImage(painter->viewport(), m_image);
    }
}
