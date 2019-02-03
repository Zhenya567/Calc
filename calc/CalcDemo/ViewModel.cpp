#include "ViewModel.h"

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

void ViewModel::InputSecondNumberState::onOperationSelected(QString operationChar)
{
    Ptr This(parent()->state());
    parent()->calculator().setSecondValue(m_secondValueBuffer);
    auto result = parent()->calculator().calculate();
    parent()->calculator().setFirstValue(result);
    parent()->calculator().setOperation(operationChar.toLocal8Bit()[0]);//
    m_secondValueBuffer = "";
}
void ViewModel::InputSecondNumberState::onEqSelected()
{
    Ptr This(parent()->state());
       parent()->calculator().setSecondValue(m_secondValueBuffer);
       parent()->setState(Ptr(new PrintResultState(parent())));
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

QString ViewModel::PrintResultState::formatLabel()
{
    return QString("%1 %2 %3 = %4")
            .arg(parent()->calculator().firstValue())
            .arg(parent()->calculator().operation())
            .arg(parent()->calculator().secondValue())
            .arg(parent()->calculator().calculate());
}
