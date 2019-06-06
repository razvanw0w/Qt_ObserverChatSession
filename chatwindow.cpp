#include "chatwindow.h"
#include "ui_chatwindow.h"
#include "message.h"

ChatWindow::ChatWindow(ChatSession *session, std::string user, QWidget *parent) :
    QWidget(parent),
    Observer{},
    ui(new Ui::ChatWindow),
    session{session},
    user{user}
{
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(user) + " chat");
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::on_sendMessagePushButton_clicked()
{
    sendMessage();
}

void ChatWindow::sendMessage()
{
    QString text = ui->messageLineEdit->text();
    ui->messageLineEdit->setText("");

    Message message{text.toStdString(), user};
    session->addMessage(message);
}

void ChatWindow::update()
{
    auto v = session->getMessages();

    ui->messageListWidget->clear();
    for (auto m: v) {
        QListWidgetItem *item = new QListWidgetItem{QString::fromStdString(m.getString())};
        if (m.getUser() == user) {
            item->setTextAlignment(Qt::AlignRight);
        }
        else {
            item->setTextAlignment(Qt::AlignLeft);
        }

        ui->messageListWidget->addItem(item);
    }
}
