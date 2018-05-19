#include "View.hpp"

#include <iostream>

View::View()
{
    layout_.addWidget(&messageText_);
    setLayout(&layout_);
}

void MessageTextEdit::keyPressEvent(QKeyEvent *event)
{
   if((event->key() == Qt::Key_Enter or
      event->key() == Qt::Key_Return) and
       event->modifiers() == Qt::NoModifier)
   {
       std::cout << "Wcisnieto enter" << std::endl;
   }
}
