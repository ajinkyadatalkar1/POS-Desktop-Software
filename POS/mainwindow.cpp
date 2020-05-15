#include "mainwindow.h"
#include "registeration.h"
#include "login.h"

mainwindow::mainwindow(){
QDesktopWidget *widget = new QDesktopWidget;
setMinimumHeight(768);
setMinimumWidth(1024);
QRect screenSize = widget->availableGeometry(widget->primaryScreen());
this->move(screenSize.height()/2,screenSize.width()/8);
add_menus();
primarylayout->setMenuBar(menubar);
webview->setUrl(QUrl(QStringLiteral("http://localhost/")));
primarylayout->addWidget(webview);
this->setLayout(primarylayout);
this->setWindowTitle("HERMES");
}

void mainwindow::add_menus(){
add_acts();
menubar->addMenu(file);
menubar->addMenu(user_management);
menubar->addMenu(help);
}

void mainwindow::add_acts(){
    about_us.setText("About");
    users.setText("Users");
    add_user.setText("Add Users");
    logout.setText("Logout");
    remove_user.setText("Remove Users");
    exit_program->setToolTip("Exit Program");
    exit_program->setText("Quit");
    file->addAction(&logout);
    file->addAction(exit_program);
    user_management->addAction(&add_user);
    user_management->addAction(&remove_user);
    help->addAction(&about_us);
    action_definations();
}

void mainwindow::action_definations(){
    registeration *main_window = new registeration();

    connect(exit_program,&QAction::triggered,[=](){
    qDebug() << "Exiting Application.";
    exit(0);
    });

    connect(&about_us,&QAction::triggered,[=](){
    launch_about();
    });

    connect(&add_user,&QAction::triggered,[=](){
    main_window->show();
    });

    connect(&logout,&QAction::triggered,[=](){
        login *start = new login;
        this->close();
        start->show();
    });
}

void mainwindow::launch_about(){
    QDialog *dialog = new QDialog;
    QLabel *text = new QLabel();
    text->setText("Designed and developed by<br /> Ajinkya,<br />Sandesh,<br />Vijay,<br />Siddhant and <br /> Sujal <br />for Computer Science Project 1.");
    QHBoxLayout hbox;
    hbox.addWidget(text);
    dialog->setWindowTitle("About");
    dialog->setLayout(&hbox);
    dialog->show();
}
