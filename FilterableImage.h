#ifndef FILTERABLEIMAGE_H
#define FILTERABLEIMAGE_H

#include <QObject>

class FilterableImage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float level READ getLevel WRITE setLevel NOTIFY levelChanged)

public:
    explicit FilterableImage(QObject *parent = 0);

    float getLevel() const;

signals:
    void levelChanged(float level);

public slots:
    void setLevel(float level);

private:
    float m_level = 0.5f;
};

#endif // FILTERABLEIMAGE_H
