#ifndef FILTERABLEIMAGE_H
#define FILTERABLEIMAGE_H

#include <QQuickPaintedItem>
#include <QImage>

class FilterableImage : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(float level READ getLevel WRITE setLevel NOTIFY levelChanged)

public:
    static QRect scaleToFitInside(const QRect& bounds, QRect originalGeometry);

    explicit FilterableImage(QQuickItem *parent = 0);

    float getLevel() const;

    virtual void paint(QPainter *painter);

signals:
    void levelChanged(float level);

public slots:
    void setLevel(float level);
    void loadFromFile(const QUrl& fileUri);
    void saveToFile(const QUrl& fileUri);

private:
    float m_level = 0.5f;
    QImage m_image;
};

#endif // FILTERABLEIMAGE_H
