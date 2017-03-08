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

void FilterableImageTest::filterIsUsed()
{
    // We expect that filter is used when an image is set to FilterableImage
    int filterCallCount = 0;
    const auto filter = [&filterCallCount](const QImage& originalImage) {
        filterCallCount++;
        return originalImage;
    };

    //const auto sut = QScopedPointer<FilterableImage>(new FilterableImage);
    const auto sut = new FilterableImage();
    auto image = QImage(50, 50, QImage::Format_ARGB32);

    QCOMPARE(filterCallCount, 0);
    sut->setImage(image);
    QCOMPARE(filterCallCount, 0);
    sut->setFilter(filter);
    QCOMPARE(filterCallCount, 1);
    sut->setImage(image);
    QCOMPARE(filterCallCount, 2);
}
