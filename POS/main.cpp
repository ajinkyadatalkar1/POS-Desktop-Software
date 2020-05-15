#include "mainwindow.h"
#include "login.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login *start = new login;
    start->show();
    return a.exec();
}
