#include "message.h"

Message::Message()
{
    this->msgBox = new QMessageBox();
    this->msgBox->setWindowTitle(" ");
    this->msgBox->setFont(QFont("Seoge Ui", 25));
    this->msgBox->setStyleSheet("border-image: url(:/images/messageBox.jpg) stretch;");

    messageTexts = {"Oops, you lost a life!",
                   "Level over!",
                   "No spare lives left.\nBetter luck next time!",
                   "Congratulations! \nYou have successfully completed the level!",
                   "Oops, you ran out of time!"};

}

void Message::setMessageText(MessageText messageValue) {
    this->msgBox->setText(messageTexts[int(messageValue)]);
    this->msgBox->exec();
}

Message::~Message(){
    delete this->msgBox;
}
