#ifndef FILTERABLEIMAGE_H
#define FILTERABLEIMAGE_H

#include <QQuickPaintedItem>

class FilterableImage : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(float level READ getLevel WRITE setLevel NOTIFY levelChanged)

public:
    explicit FilterableImage(QQuickItem *parent = 0);

    float getLevel() const;

    virtual void paint(QPainter *painter);

signals:
    void levelChanged(float level);

public slots:
    void setLevel(float level);

private:
    float m_level = 0.5f;
};

#endif // FILTERABLEIMAGE_H
