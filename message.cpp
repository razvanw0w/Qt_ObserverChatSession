#include "message.h"

Message::Message(std::string t, std::string u): text{t}, user{u}
{

}

std::string Message::getMessage() const
{
    return text;
}

std::string Message::getUser() const
{
    return user;
}

std::string Message::getString() const
{
    return user + ": " + text;
}
