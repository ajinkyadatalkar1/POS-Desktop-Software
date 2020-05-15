#ifndef LOGIN_H
#define LOGIN_H

#include "mainwindow.h"

class login : public QDialog{
public:
    login();
    QGridLayout *grid_layout = new QGridLayout();
    QLineEdit *username = new QLineEdit();
    QLineEdit *password = new QLineEdit();
    QPushButton *login_btn = new QPushButton("Login");
    QPushButton *quit_btn = new QPushButton("Quit");

    QDialog *error_dialog = new QDialog();
    QHBoxLayout *dialog_layout = new QHBoxLayout();
    QLabel *dialog_msg = new QLabel();
    QPushButton *ok = new QPushButton("OK");
};

#endif // LOGIN_H
