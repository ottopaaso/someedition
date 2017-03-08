#ifndef FILTERABLEIMAGE_H
#define FILTERABLEIMAGE_H

#include <QQuickPaintedItem>
#include <QImage>

#include <functional>

class FilterableImage : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(float level READ getLevel WRITE setLevel NOTIFY levelChanged)

public:
    typedef std::function<QImage(const QImage&, float)> FILTER_T;

    static QRect scaleToFitInside(const QRect& bounds, QRect originalGeometry);

    explicit FilterableImage(QQuickItem *parent = 0);

    float getLevel() const;

    virtual void paint(QPainter *painter);

signals:
    void levelChanged(float level);

public slots:
    void setLevel(float level);
    void loadFromFile(const QUrl& fileUri);
    void setImage(const QImage& image);
    void saveToFile(const QUrl& fileUri);
    void setFilter(const FILTER_T& filter);


private:
    float m_level = 0.5f;
    QImage m_image;
    FILTER_T m_filter = [](const QImage& image, float) {
        return image;
    };
    QImage m_filteredImage;

    void applyImageFilter();
};

#endif // FILTERABLEIMAGE_H
