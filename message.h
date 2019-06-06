#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>

class Message
{
private:
    std::string text;
    std::string user;

public:
    Message(std::string t = "", std::string u = "");
    std::string getMessage() const;
    std::string getUser() const;
    std::string getString() const;
};

#endif // MESSAGE_H
