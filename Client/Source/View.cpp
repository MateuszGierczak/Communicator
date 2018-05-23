#include "View.hpp"

#include <iostream>

namespace
{
bool isEnterPressedWithoutModifiers(const QKeyEvent& event)
{
    return (event.key() == Qt::Key_Enter or event.key() == Qt::Key_Return) and
            event.modifiers() == Qt::NoModifier;
}
}

View::View()
{
    layout_.addWidget(&messageText_);
    setLayout(&layout_);
}

void MessageTextEdit::keyPressEvent(QKeyEvent *event)
{
   if(isEnterPressedWithoutModifiers(*event))
   {
       std::cout << "Enter pressed" << std::endl;
   }
}
