#ifndef FILTERABLEIMAGETEST_H
#define FILTERABLEIMAGETEST_H

#include <QObject>

class FilterableImageTest : public QObject
{
    Q_OBJECT
public:
    explicit FilterableImageTest(QObject *parent = 0);

private slots:
    void scaleToFitInside();
    void filterIsUsed();
};

#endif // FILTERABLEIMAGETEST_H
