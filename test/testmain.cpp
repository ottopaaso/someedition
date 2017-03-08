#include <stdio.h>
#include <QTest>
#include <QList>

#include "FilterableImageTest.h"

int main(int argc, char* argv[])
{
    QList<QObject*> tests;

    tests << new FilterableImageTest();

    for (QObject* test : tests) {
        QTest::qExec(test);
        test->deleteLater();
    }

    return 0;
}
