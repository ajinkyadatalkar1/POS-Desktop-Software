#include "login.h"
#include "mainwindow.h"
#include <QDebug>

login::login()
{
mainwindow *window = new mainwindow();
this->setWindowTitle("HERMES");

username->setPlaceholderText("Username");
password->setPlaceholderText("Password");
password->setEchoMode(QLineEdit::Password);

this->setFixedHeight(100);
this->setFixedWidth(400);

grid_layout->addWidget(username,0,0,1,3);
grid_layout->addWidget(password,1,0,1,3);
grid_layout->addWidget(login_btn,2,0,1,2);
grid_layout->addWidget(quit_btn,2,2,1,1);
setLayout(grid_layout);


connect(login_btn,&QPushButton::clicked,[=](){
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("bill");
    db.setUserName("ajinkya");
    db.setPassword("apache8812");
    QString user_name = username->text();
    QString pass = password->text();

 /*   QSqlQuery query(db);

    QVariant u_name_varient,pass_varient;
    if(db.open()){
        query.prepare("SELECT username,password FROM users WHERE username=? AND password=?");
        query.addBindValue(user_name);
        query.addBindValue(pass);
        if(query.exec()){
            query.first();
            u_name_varient = query.value(0);
            pass_varient = query.value(1);
            if(user_name == u_name_varient && pass == pass_varient){
             window->show();
             this->close();
            }
            else {
                dialog_msg->setText("Please enter a vaild username and password.");
                dialog_layout->addWidget(dialog_msg);
                dialog_layout->addWidget(ok);
                error_dialog->setLayout(dialog_layout);
                error_dialog->show();
            }
        }
    }
    else{
        dialog_msg->setText("Error connecting to the database.");
        dialog_layout->addWidget(dialog_msg);
        dialog_layout->addWidget(ok);
        error_dialog->setLayout(dialog_layout);
        error_dialog->show();
    }*/
    window->show();
});

connect(quit_btn,&QPushButton::clicked,[=](){
    qApp->exit(0);
});

connect(ok,&QPushButton::clicked,[=](){
    error_dialog->close();
});
}
