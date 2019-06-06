#include "chatwindow.h"
#include "chatsession.h"
#include "subject.h"
#include "observer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatSession *session = new ChatSession;
    std::string users[] = {"user1", "user2", "user3", "user4"};
    ChatWindow *chatWindow1 = new ChatWindow{session, users[0], nullptr};
    ChatWindow *chatWindow2 = new ChatWindow{session, users[1], nullptr};
    ChatWindow *chatWindow3 = new ChatWindow{session, users[2], nullptr};
    ChatWindow *chatWindow4 = new ChatWindow{session, users[3], nullptr};

    session->registerObserver(chatWindow1);
    session->registerObserver(chatWindow2);
    session->registerObserver(chatWindow3);
    session->registerObserver(chatWindow4);

    chatWindow1->show();
    chatWindow2->show();
    chatWindow3->show();
    chatWindow4->show();
    return a.exec();
}
