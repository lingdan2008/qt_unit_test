#include "calc.h"
#include <QtTest>


Calc::Calc()
{
    qDebug() << __FUNCTION__;
}

int Calc::add(int x, int y)
{
    return x + y;
}

void Calc::test_case1()
{
    bool isEnable = true;
    QVERIFY(isEnable);
}

void Calc::test_case2()
{
    QString name("AutoTest");
    QCOMPARE(name, QString("AutoTest"));
}

void Calc::test_case3()
{
    QFETCH(int, input);
    QFETCH(int, raw_result);

    QCOMPARE(input, raw_result);
}

void Calc::test_case3_data()
{
    QTest::addColumn<int>("input");
    QTest::addColumn<int>("raw_result");

    QTest::addRow("1") << 1 << 1;
    QTest::addRow("2") << 3 << add(1, 2);
}

QTEST_APPLESS_MAIN(Calc)
