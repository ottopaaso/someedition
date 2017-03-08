#include "filterableimagetest.h"

#include "FilterableImage.h"

#include <QTest>

FilterableImageTest::FilterableImageTest(QObject *parent) : QObject(parent)
{

}

void FilterableImageTest::scaleToFitInside()
{
    // Already fits
    {
        const QRect bounds(QPoint(0, 0), QPoint(10, 10));
        const QRect geometry(QPoint(1, 1), QPoint(9, 9));
        const auto result = FilterableImage::scaleToFitInside(bounds, geometry);

        QCOMPARE(result.topLeft(), QPoint(1, 1));
        QCOMPARE(result.bottomRight(), QPoint(9, 9));
    }

    // Originally too high
    {
        const QRect bounds(QPoint(0, 0), QPoint(10, 10));
        const QRect geometry(QPoint(0, 0), QPoint(10, 20));
        const auto result = FilterableImage::scaleToFitInside(bounds, geometry);

        QCOMPARE(result.topLeft(), QPoint(3, 0));
        QCOMPARE(result.bottomRight(), QPoint(7, 10));
    }

    // Originally too wide
    {
        const QRect bounds(QPoint(0, 0), QPoint(10, 10));
        const QRect geometry(QPoint(0, 0), QPoint(20, 10));
        const auto result = FilterableImage::scaleToFitInside(bounds, geometry);

        QCOMPARE(result.topLeft(), QPoint(0, 3));
        QCOMPARE(result.bottomRight(), QPoint(10, 7));
    }
}
