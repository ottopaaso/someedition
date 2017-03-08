#include "FilterableImage.h"

#include <QPainter>

QRect FilterableImage::scaleToFitInside(const QRect& bounds, QRect geometry)
{
    geometry.moveCenter(bounds.center());
    if (bounds.contains(geometry)) {
        return geometry;
    }

    const auto& boundSize = bounds.size();
    const auto& rectSize = geometry.size();

    const auto aspectRatio = (double) rectSize.height() / rectSize.width();
    const auto factor = aspectRatio > 1.0 ?
                (double) boundSize.height() / rectSize.height() :
                (double) boundSize.width() / rectSize.width();

    geometry.setSize( QSize(factor * rectSize.width(), factor * rectSize.height()) );
    geometry.moveCenter(bounds.center());

    return geometry;
}

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
    applyImageFilter();
    update();
}

#include <QDebug>

void FilterableImage::loadFromFile(const QUrl& fileUri)
{
    setImage( QImage( fileUri.toLocalFile() ) );

    if (m_image.isNull()) {
        qDebug() << "Loading image from" << fileUri << " failed!";
    }
}

void FilterableImage::setImage(const QImage &image)
{
    m_image = image;
    applyImageFilter();
    update();
}

void FilterableImage::saveToFile(const QUrl& fileUri)
{
    if (!m_image.isNull()) {
        qDebug() << "Saving to" << fileUri;
        m_image.save(fileUri.toLocalFile());
    }
}

void FilterableImage::setFilter(const FilterableImage::FILTER_T& filter)
{
    m_filter = filter;
    applyImageFilter();
}

void FilterableImage::applyImageFilter()
{
    m_filteredImage = m_filter(m_image, m_level);
}

void FilterableImage::paint(QPainter * painter)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    if (!m_image.isNull()) {
        painter->drawImage( scaleToFitInside(painter->viewport(), m_filteredImage.rect()), m_filteredImage);
    }
}
