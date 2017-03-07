#include "FilterableImage.h"

FilterableImage::FilterableImage(QObject *parent) : QObject(parent)
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

    fprintf(stderr, "Level set to %.3f\n", level);

    m_level = level;
    emit levelChanged(level);
}
