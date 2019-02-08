#include "ViewModel.h"
#include <QDebug>

ViewModel::ViewModel(QObject *parent): QObject(parent)
{
    setState(State::Ptr(new InputFirstNumberState(this)));
}

ViewModel::~ViewModel()
{

}

void ViewModel::onNumberSelected(QString numberChar)
{
    m_state->onNumberSelected(numberChar);
    sendUpdateLabel(m_state->formatLabel());
}

void ViewModel::onOperationSelected(QString operationChar)
{
    m_state->onOperationSelected(operationChar);
    sendUpdateLabel(m_state->formatLabel());
}

void ViewModel::onEqSelected()
{
    m_state->onEqSelected();
    sendUpdateLabel(m_state->formatLabel());
}
void ViewModel::clear()
{
    m_state->clear();
    sendUpdateLabel(m_state->formatLabel());
}
void ViewModel::plus_minus()
{
    m_state->plus_minus();
    sendUpdateLabel(m_state->formatLabel());
}
void ViewModel::percent()
{
    m_state->percent();
    sendUpdateLabel(m_state->formatLabel());
}
void ViewModel::dot()
{
    m_state->dot();
    sendUpdateLabel(m_state->formatLabel());
}
void ViewModel::backspace()
{
    m_state->backspace();
    sendUpdateLabel(m_state->formatLabel());
}
/*-----------------*/
ViewModel::State::Ptr ViewModel::state() const
{
    return m_state;
}

void ViewModel::setState(const State::Ptr &state)
{
    m_state = state;
    if (m_state) {
        sendUpdateLabel(m_state->formatLabel());
    }
}

Calculator& ViewModel::calculator()
{
    return m_calculator;
}

void ViewModel::sendUpdateLabel(QString label)
{
    //emit updateLabel(label);
    qDebug() << Q_FUNC_INFO;
        qDebug() << "Text label: \n" << label;
        qDebug() << "First value: " << m_calculator.firstValue();
        qDebug() << "Operation: "<< m_calculator.operation();
        qDebug() << "Second value: "<< m_calculator.secondValue();

        emit updateLabel(label);
}

QStringList ViewModel::operations()
{
    QStringList result;
    for (auto ch : calculator().availibleOperations())
    {
        result.append(QString(ch));
    }
    return result;
}

ViewModel* ViewModel::State::parent() const
{
    return m_parent;
}

ViewModel::State::State(ViewModel *parent) {m_parent = parent;}

ViewModel::State::~State() {}

ViewModel::InputFirstNumberState::InputFirstNumberState(ViewModel *parent): State (parent)
{

}

void ViewModel::InputFirstNumberState::onNumberSelected(QString numberChar)
{
   m_firstValueBuffer += numberChar;

   //parent()->calculator().setFirstValue(result);

}

void ViewModel::InputFirstNumberState::onOperationSelected(QString operationChar)
{


    Ptr This(parent()->state());
    parent()->calculator().setFirstValue(m_firstValueBuffer);
    parent()->calculator().setOperation(operationChar.toLocal8Bit()[0]);

    parent()->setState(Ptr(new InputSecondNumberState(parent())));

}

void ViewModel::InputFirstNumberState::onEqSelected()
{

}
void ViewModel::InputFirstNumberState::clear()
{
    parent()->calculator().clear();
    m_firstValueBuffer="";
    parent()->setState(Ptr(new InputFirstNumberState(parent())));

    //parent()->calculator().setOperation(0);
    //parent()->setState(Ptr(new InputFirstNumberState(parent())));
}
void ViewModel::InputFirstNumberState::plus_minus()
{
    m_firstValueBuffer = QString::number(m_firstValueBuffer.toDouble()*-1);
}
void ViewModel::InputFirstNumberState::percent()
{
    m_firstValueBuffer = QString::number(m_firstValueBuffer.toDouble()*0.01);
}
void ViewModel::InputFirstNumberState::dot()
{
    if(m_firstValueBuffer!=""){
    m_firstValueBuffer = m_firstValueBuffer+".";
    }
}
void ViewModel::InputFirstNumberState::backspace()
{

    if(m_firstValueBuffer!=""){
   m_firstValueBuffer.remove(m_firstValueBuffer.size() - 1, 1);}

}

QString ViewModel::InputFirstNumberState::formatLabel()
{
    return QString("%1").arg(m_firstValueBuffer);

}

ViewModel::InputSecondNumberState::InputSecondNumberState(ViewModel *parent): State (parent)
{

}

void ViewModel::InputSecondNumberState::onNumberSelected(QString numberChar)
{
    m_secondValueBuffer += numberChar;

}

/*void ViewModel::InputSecondNumberState::onOperationSelected(QString operationChar)
{
    Ptr This(parent()->state());
    parent()->calculator().setSecondValue(m_secondValueBuffer);
    auto result = parent()->calculator().calculate();
    parent()->calculator().setFirstValue(result);
    parent()->calculator().setOperation(operationChar.toLocal8Bit()[0]);//
    m_secondValueBuffer = "";
}*/
void ViewModel::InputSecondNumberState::onOperationSelected(QString operationChar)
{


    Ptr This(parent()->state());
   if (m_secondValueBuffer != "") {

        parent()->calculator().setSecondValue(m_secondValueBuffer);
        auto result = parent()->calculator().calculate();
        parent()->calculator().setFirstValue(result);
        parent()->calculator().setOperation(operationChar.toLocal8Bit()[0]);
         //oper1+=operationChar;
        m_secondValueBuffer = "";
    } else {
        parent()->calculator().setOperation(operationChar.toLocal8Bit()[0]);
        //oper1+=operationChar;

    }
}
void ViewModel::InputSecondNumberState::onEqSelected()
{
    Ptr This(parent()->state());
       parent()->calculator().setSecondValue(m_secondValueBuffer);
       parent()->setState(Ptr(new PrintResultState(parent())));
}
void ViewModel::InputSecondNumberState::clear()
{
    parent()->calculator().clear();
    m_secondValueBuffer="";
    parent()->setState(Ptr(new InputFirstNumberState(parent())));

}
void ViewModel::InputSecondNumberState::plus_minus()
{
    if (m_secondValueBuffer != "") {
   m_secondValueBuffer = QString::number(m_secondValueBuffer.toDouble()*-1);}

}
void ViewModel::InputSecondNumberState::percent()
{
    m_secondValueBuffer = QString::number(m_secondValueBuffer.toDouble()*0.01);
}
void ViewModel::InputSecondNumberState::dot()
{
    m_secondValueBuffer = m_secondValueBuffer+".";
}
void ViewModel::InputSecondNumberState::backspace()
{
   /*if(oper1!=""){
       parent()->setState(Ptr(new InputFirstNumberState(parent())));
   }*/
    if(m_secondValueBuffer!=""){
        m_secondValueBuffer.remove(m_secondValueBuffer.size() - 1, 1);
    } else {
        //parent()->calculator().setOperation();
        parent()->calculator().setOperation(0);
        parent()->setState(Ptr(new InputFirstNumberState(parent())));
        parent()->calculator().backspace();

    }

}

QString ViewModel::InputSecondNumberState::formatLabel()
{
    return QString("%1 %2 %3")
             .arg(parent()->calculator().firstValue())
            .arg(parent()->calculator().operation())
            .arg(m_secondValueBuffer);
}

ViewModel::PrintResultState::PrintResultState(ViewModel *parent): State (parent)
{

}

void ViewModel::PrintResultState::onNumberSelected(QString numberChar)
{

}

void ViewModel::PrintResultState::onOperationSelected(QString operationChar)
{

}
void ViewModel::PrintResultState::onEqSelected()
{

}
void ViewModel::PrintResultState::clear()
{
    parent()->calculator().clear();
    parent()->setState(Ptr(new InputFirstNumberState(parent())));
}
void ViewModel::PrintResultState::plus_minus()
{

}
void ViewModel::PrintResultState::percent()
{

}
void ViewModel::PrintResultState::dot()
{

}
void ViewModel::PrintResultState::backspace()
{

}
QString ViewModel::PrintResultState::formatLabel()
{
    return QString("%1 %2 %3 = %4")
            .arg(parent()->calculator().firstValue())
            .arg(parent()->calculator().operation())
            .arg(parent()->calculator().secondValue())
            .arg(parent()->calculator().calculate());
}
