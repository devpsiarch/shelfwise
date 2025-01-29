/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QFrame *main_login;
    QWidget *widget;
    QLineEdit *email_in;
    QLineEdit *password_in;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;
    QWidget *Interface;
    QLabel *label;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(1104, 819);
        login->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        main_login = new QFrame(centralwidget);
        main_login->setObjectName("main_login");
        main_login->setGeometry(QRect(260, 110, 541, 621));
        main_login->setFrameShape(QFrame::Shape::StyledPanel);
        main_login->setFrameShadow(QFrame::Shadow::Raised);
        widget = new QWidget(main_login);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 230, 431, 291));
        email_in = new QLineEdit(widget);
        email_in->setObjectName("email_in");
        email_in->setGeometry(QRect(20, 50, 391, 26));
        QFont font;
        font.setFamilies({QString::fromUtf8("Sans Serif")});
        font.setPointSize(11);
        email_in->setFont(font);
        email_in->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        password_in = new QLineEdit(widget);
        password_in->setObjectName("password_in");
        password_in->setGeometry(QRect(20, 120, 391, 26));
        password_in->setFont(font);
        password_in->setAutoFillBackground(false);
        password_in->setEchoMode(QLineEdit::EchoMode::Password);
        password_in->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        password_in->setReadOnly(false);
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 131, 18));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("JetBrainsMono Nerd Font")});
        font1.setPointSize(12);
        label_2->setFont(font1);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 90, 91, 18));
        label_3->setFont(font1);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 190, 391, 26));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("JetBrainsMono Nerd Font")});
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("background-color:rgb(32, 148, 243);\n"
"color:rgb(255, 255, 255);"));
        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(180, 230, 71, 18));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("JetBrainsMono Nerd Font")});
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setUnderline(true);
        label_4->setFont(font3);
        Interface = new QWidget(main_login);
        Interface->setObjectName("Interface");
        Interface->setGeometry(QRect(60, 120, 431, 111));
        QFont font4;
        font4.setPointSize(11);
        font4.setUnderline(false);
        Interface->setFont(font4);
        label = new QLabel(Interface);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 40, 291, 41));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("JetBrainsMono Nerd Font")});
        font5.setPointSize(18);
        font5.setUnderline(false);
        label->setFont(font5);
        login->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName("statusbar");
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "shelfwise", nullptr));
        email_in->setText(QString());
        password_in->setText(QString());
        label_2->setText(QCoreApplication::translate("login", "School Email:", nullptr));
        label_3->setText(QCoreApplication::translate("login", "Password:", nullptr));
        pushButton->setText(QCoreApplication::translate("login", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("login", "Sign in ?", nullptr));
        label->setText(QCoreApplication::translate("login", "Welcome to Shelfwise", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
