#ifndef FILTERABLEIMAGE_H
#define FILTERABLEIMAGE_H

#include <QObject>

class FilterableImage : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ getText() CONSTANT)

public:
    explicit FilterableImage(QObject *parent = 0);

signals:

public slots:
    QString getText() { return QString("Hello World!"); }
};

#endif // FILTERABLEIMAGE_H
