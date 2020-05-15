#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QRect>
#include <QDesktopWidget>
#include <QMenu>
#include <QAction>

#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QCalendarWidget>
#include <QPushButton>

#include <QWebEngineView>
#include <QtSql>
#include <QSqlDatabase>

#include <QMenuBar>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>

#include <QString>
#include <QDebug>

class mainwindow : public QWidget {
public:
  mainwindow();

private:

  void add_acts();
  void add_menus();
  void action_definations();

  QAction users,about_us,add_user,remove_user,logout;
  QAction *exit_program = new QAction();

  QMenu *file = new QMenu("File");
  QMenu *help = new QMenu("Help");
  QMenu *user_management = new QMenu("Manage Users");
  QMenuBar *menubar = new QMenuBar();
  QWebEngineView *webview = new QWebEngineView();

  QGridLayout *primarylayout = new QGridLayout();

signals:
    void about();

public slots:
    void launch_about();
};

#endif // MAINWINDOW_H
