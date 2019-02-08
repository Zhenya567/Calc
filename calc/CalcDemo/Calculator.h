#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QString>
#include <QList>
#include <QMap>

class Calculator
{
public:
    Calculator();

    QString firstValue() const;
    void setFirstValue(const QString &firstValue);

    QString secondValue() const;
    void setSecondValue(const QString &secondValue);


    char operation() const;
    void setOperation(char operation);

    QString calculate();
    void clear();
    void backspace();
    QList<char> availibleOperations();


private:
    QString m_firstValue;
    QString m_secondValue;
    char m_operation;

    typedef double (*Operation)(double, double);
    QMap<char, Operation> operations;
};

#endif // CALCULATOR_H
