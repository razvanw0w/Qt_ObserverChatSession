#ifndef CHATSESSION_H
#define CHATSESSION_H

#include "subject.h"
#include "message.h"

class ChatSession: public Subject
{
public:
    ChatSession();
    void addMessage(const Message& message);
    std::vector<Message> getMessages();

private:
    std::vector <Message> messages;
};

#endif // CHATSESSION_H
