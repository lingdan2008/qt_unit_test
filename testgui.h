#ifndef TESTGUI_H
#define TESTGUI_H

#include <QObject>

class TestGUI : public QObject
{
    Q_OBJECT
public:
    explicit TestGUI(QObject *parent = nullptr);

private slots:
    void testControl();

    void testEvent();
    void testEvent_data();

signals:

public slots:
};

#endif // TESTGUI_H
