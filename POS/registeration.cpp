#include "registeration.h"

registeration::registeration()
{
        this->setWindowTitle("Register New User");
        QRect screenSize = widget->availableGeometry(widget->primaryScreen());
        this->move(screenSize.height()/2,screenSize.width()/8);


        f_name->setPlaceholderText("First Name");
        l_name->setPlaceholderText("Last Name");
        age->setPlaceholderText("Age");
        username->setPlaceholderText("Username");
        password->setPlaceholderText("Password");
        password->setEchoMode(QLineEdit::Password);

        QString gender_list[] = {"Select Gender","M","F"};
        for(int i=0;i<=2;i++){
            gender->addItem(gender_list[i]);
        }

        layout->addWidget(f_name,0,0);
        layout->addWidget(l_name,0,1);
        layout->addWidget(gender,2,0,1,1);
        layout->addWidget(age,2,1,1,1);
        layout->addWidget(username,3,0,1,1);
        layout->addWidget(password,3,1,1,1);
        layout->addWidget(reset,4,0,1,2);
        layout->addWidget(submit,5,0,1,2);
        setLayout(layout);


        connect(reset,&QPushButton::clicked,[=](){
            f_name->clear();
            l_name->clear();
            gender->setCurrentIndex(0);
            age->clear();
            username->clear();
            password->clear();
        });

        connect(submit,&QPushButton::clicked,[=](){
            QSqlDatabase db;
            db = QSqlDatabase::addDatabase("QMYSQL");
            db.setHostName("localhost");
            db.setDatabaseName("bill");
            db.setUserName("ajinkya");
            db.setPassword("password");
            QString user_name = username->text();
            QString pass = password->text();

            QSqlQuery query(db);

            if(db.open()){
                query.prepare("INSERT INTO users (firstname,lastname,gender,age,username,password) VALUES (?,?,?,?,?,?)");
                query.addBindValue(f_name->text());
                query.addBindValue(l_name->text());
                query.addBindValue(gender->currentText());
                query.addBindValue(age->text());
                query.addBindValue(username->text());
                query.addBindValue(password->text());
                if(query.exec()){
                    status->setText("Record added Successfully!");
                    status_dialog_layout->addWidget(status);
                    status_dialog_layout->addWidget(cancel);
                    status_dialog->setLayout(status_dialog_layout);
                    this->close();
                    status_dialog->show();
                }
                else {
                    status->setText("There was an error adding record.");
                    status_dialog_layout->addWidget(status);
                    status_dialog_layout->addWidget(cancel);
                    status_dialog->setLayout(status_dialog_layout);
                    status_dialog->show();
                }
            }
        });

        connect(cancel,&QPushButton::clicked,[=](){
            status_dialog->close();
            this->close();
        });
}
