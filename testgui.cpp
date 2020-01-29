#include "testgui.h"
#include <QLineEdit>
#include <QTest>

TestGUI::TestGUI(QObject *parent) : QObject(parent)
{

}

void TestGUI::testControl()
{
    QLineEdit lineEdit;
    QTest::keyClicks(&lineEdit, "hello, world");

    QCOMPARE(lineEdit.text(), QString("hello, world"));
}

void TestGUI::testEvent()
{
    QFETCH(QTestEventList, events);
    QFETCH(QString, expected);

    QLineEdit lineEdit;
    events.simulate(&lineEdit);

    QCOMPARE(lineEdit.text(), expected);
}

void TestGUI::testEvent_data()
{
    QTest::addColumn<QTestEventList>("events");
    QTest::addColumn<QString>("expected");

    QTestEventList list1;
    list1.addKeyClick('a');
    QTest::addRow("char") << list1 << "a";

    QTestEventList list2;
    list2.addKeyClick('a');
    list2.addKeyClick(Qt::Key_Backspace);
    QTest::addRow("there and back agin") << list2 << "";
}

QTEST_MAIN(TestGUI)
