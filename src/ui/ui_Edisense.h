/********************************************************************************
** Form generated from reading UI file 'Edisense.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDISENSE_H
#define UI_EDISENSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDetect_Edisons;
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QDial *TokenDial;
    QComboBox *comboBox;
    QLCDNumber *TokenDisplay;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QWidget *tab_2;
    QTableView *tableView;
    QWidget *tab_3;
    QMenuBar *menubar;
    QMenu *menuNetwork;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(505, 284);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionDetect_Edisons = new QAction(MainWindow);
        actionDetect_Edisons->setObjectName(QStringLiteral("actionDetect_Edisons"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 481, 211));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        TokenDial = new QDial(tab);
        TokenDial->setObjectName(QStringLiteral("TokenDial"));
        TokenDial->setGeometry(QRect(20, 10, 161, 131));
        TokenDial->setMaximum(23);
        TokenDial->setInvertedAppearance(false);
        TokenDial->setInvertedControls(false);
        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(180, 70, 121, 26));
        TokenDisplay = new QLCDNumber(tab);
        TokenDisplay->setObjectName(QStringLiteral("TokenDisplay"));
        TokenDisplay->setGeometry(QRect(180, 40, 121, 23));
        TokenDisplay->setAutoFillBackground(false);
        TokenDisplay->setStyleSheet(QStringLiteral("QLCDNumber { background-color:black }"));
        TokenDisplay->setFrameShape(QFrame::Box);
        TokenDisplay->setFrameShadow(QFrame::Raised);
        TokenDisplay->setLineWidth(1);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(310, 40, 51, 20));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 70, 41, 21));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 100, 161, 32));
        tabWidget->addTab(tab, QString());
        TokenDial->raise();
        comboBox->raise();
        TokenDisplay->raise();
        label->raise();
        label_2->raise();
        pushButton->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView = new QTableView(tab_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 0, 256, 181));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 505, 22));
        menuNetwork = new QMenu(menubar);
        menuNetwork->setObjectName(QStringLiteral("menuNetwork"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuNetwork->menuAction());
        menuNetwork->addAction(actionDetect_Edisons);

        retranslateUi(MainWindow);
        QObject::connect(TokenDial, SIGNAL(valueChanged(int)), TokenDisplay, SLOT(display(int)));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionDetect_Edisons->setText(QApplication::translate("MainWindow", "Detect Edisons", 0));
        label->setText(QApplication::translate("MainWindow", "Token", 0));
        label_2->setText(QApplication::translate("MainWindow", "Node", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Sync Configuration", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Configuration", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Monitor", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Client", 0));
        menuNetwork->setTitle(QApplication::translate("MainWindow", "Network", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDISENSE_H
