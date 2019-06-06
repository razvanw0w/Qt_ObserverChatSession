#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QWidget>
#include "observer.h"
#include "message.h"
#include "chatsession.h"
#include <string>

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QWidget, public Observer
{
    Q_OBJECT

public:
    explicit ChatWindow(ChatSession* session, std::string user = "", QWidget *parent = nullptr);
    ~ChatWindow() override;

private slots:
    void on_sendMessagePushButton_clicked();

private:
    Ui::ChatWindow *ui;
    ChatSession *session;
    std::string user;

    void sendMessage();
    void update() override;
};

#endif // CHATWINDOW_H
