#include "chatsession.h"
#include <QDebug>

const int DEBUG = 0;

ChatSession::ChatSession(): Subject{}
{

}

void ChatSession::addMessage(const Message &message)
{
    if (DEBUG) {
        qDebug() << QString::fromStdString(message.getString());
    }
    messages.push_back(message);
    notify();
}

std::vector<Message> ChatSession::getMessages()
{
    return messages;
}
