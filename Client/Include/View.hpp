#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QPlainTextEdit>

class MessageTextEdit : public QPlainTextEdit
{
    Q_OBJECT
private:
    void keyPressEvent(QKeyEvent* event) override;
};

class View : public QWidget
{
    Q_OBJECT
public:
    View();
private:
    QGridLayout layout_;
    MessageTextEdit messageText_;
};
