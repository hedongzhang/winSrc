/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTabWidget *tabWidget;
    QWidget *widget;
    QWidget *tab_2;
    QTextBrowser *textBrowser;
    QWidget *tab;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(650, 450);
        MainWindow->setMinimumSize(QSize(650, 450));
        MainWindow->setMaximumSize(QSize(650, 450));
        QIcon icon;
        icon.addFile(QStringLiteral("D:/download/chrome/20150715044853541_easyicon_net_32.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(510, 380, 131, 51));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 631, 371));
        tabWidget->setTabBarAutoHide(false);
        widget = new QWidget();
        widget->setObjectName(QStringLiteral("widget"));
        tabWidget->addTab(widget, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 611, 331));
        textBrowser->setSource(QUrl(QString::fromUtf8("file:///C:/Users/HDZhang/Desktop/\346\226\260\345\273\272\346\226\207\346\234\254\346\226\207\346\241\243.txt")));
        textBrowser->setOpenLinks(false);
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 581, 151));
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "AutoCoding", 0));
        action->setText(QApplication::translate("MainWindow", "\346\226\207\346\241\243", 0));
        action_2->setText(QApplication::translate("MainWindow", "\350\257\264\346\230\216", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\347\224\237\346\210\220", 0));
        tabWidget->setTabText(tabWidget->indexOf(widget), QApplication::translate("MainWindow", "\351\205\215\347\275\256", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\345\270\256\345\212\251", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; font-weight:600;\">\345\220\215\347\247\260\357\274\232AutoCoding</span></p><p><span style=\" font-size:10pt; font-weight:600;\">\344\275\234\350\200\205\357\274\232\345\274\240\350\264\272\344\270\234</span></p><p><span style=\" font-size:10pt; font-weight:600;\">\345\205\254\345\217\270\357\274\232\346\267\261\345\234\263\345\270\202\345\244\251\346\272\220\350\277\252\347\247\221</span></p><p><span style=\" font-size:10pt; font-weight:600;\">\347\211\210\346\234\254\357\274\232V1.0</span></p><p><span style=\" font-size:10pt; font-weight:600;\">\346\227\245\346\234\237\357\274\2322015.7.15</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\350\257\264\346\230\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
