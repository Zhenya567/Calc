#include "Calculator.h"
#include <QMap>

double add(double val1, double val2) {
    return val1+val2;
}
double remove(double val1, double val2) {
    return val1 - val2;
}
double mult(double val1, double val2) {
    return val1 * val2;
}
double div(double val1, double val2) {
    return val1 / val2;
}
Calculator::Calculator():
    operations ({
        {'+', add},
        {'-', remove},
        {'*',mult},
        {'/',div}
    })
{

}

QString Calculator::firstValue() const
{
    return m_firstValue;
}

void Calculator::setFirstValue(const QString &firstValue)
{
    m_firstValue = firstValue;
}

QString Calculator::secondValue() const
{
    return m_secondValue;
}

void Calculator::setSecondValue(const QString &secondValue)
{
    m_secondValue = secondValue;
}

char Calculator::operation() const
{
    return m_operation;
}

void Calculator::setOperation(char operation)
{
    m_operation = operation;
}
void Calculator::clear(){
    m_operation=' ';

}
void Calculator::backspace(){
    Calculator a;
    a.firstValue();
}
QString Calculator::calculate()
{
    return QString::number(
                operations[m_operation](m_firstValue.toDouble(), m_secondValue.toDouble())
            );
}

QList<char> Calculator::availibleOperations()
{
    return operations.keys();
}
