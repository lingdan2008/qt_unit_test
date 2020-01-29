#ifndef CALC_H
#define CALC_H
#include <QObject>

class Calc : public QObject
{
    Q_OBJECT
public:
    Calc();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();
    void test_case3_data();

public:
    int add(int x, int y);

};

#endif // CALC_H
