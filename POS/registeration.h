#ifndef REGISTERATION_H
#define REGISTERATION_H

#include "mainwindow.h"

class registeration : public QWidget
{
public:
    registeration();
    QDesktopWidget *widget = new QDesktopWidget;
    QLineEdit *f_name = new QLineEdit();
    QLineEdit *l_name = new QLineEdit();
    QLineEdit *username = new QLineEdit();
    QLineEdit *password = new QLineEdit();
    QLineEdit *age = new QLineEdit();
    QComboBox *gender = new QComboBox();

    QPushButton *submit = new QPushButton("Submit");
    QPushButton *reset = new QPushButton("Reset");
    QGridLayout *layout = new QGridLayout();



    //Elements for dialog
    QDialog *status_dialog = new QDialog();
    QHBoxLayout *status_dialog_layout = new QHBoxLayout();
    QLabel *status = new QLabel();
    QPushButton *cancel = new QPushButton("OK");
};

#endif // REGISTERATION_H
