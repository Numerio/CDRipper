/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat May 26 13:21:55 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart;
    QAction *actionStop;
    QAction *actionAdd_file;
    QAction *actionAdd_ripped_file;
    QAction *actionExit;
    QAction *actionNewProject;
    QAction *actionSave;
    QAction *actionSettings;
    QAction *actionCDTracks;
    QAction *actionLoad;
    QAction *actionAddfile;
    QAction *actionAddripped;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *removeFile;
    QPushButton *upFile;
    QPushButton *downFile;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QTableWidget *tableWidget_2;
    QPushButton *removeRippedFile;
    QPushButton *upRippedFile;
    QPushButton *downRippedFile;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *cleanAll;
    QLCDNumber *durationView;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QTextBrowser *textBrowser;
    QPushButton *manualRename;
    QCheckBox *autoRename;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *durationButton;
    QLabel *label;
    QLineEdit *albumName;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(922, 681);
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        actionAdd_file = new QAction(MainWindow);
        actionAdd_file->setObjectName(QString::fromUtf8("actionAdd_file"));
        actionAdd_ripped_file = new QAction(MainWindow);
        actionAdd_ripped_file->setObjectName(QString::fromUtf8("actionAdd_ripped_file"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionNewProject = new QAction(MainWindow);
        actionNewProject->setObjectName(QString::fromUtf8("actionNewProject"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionCDTracks = new QAction(MainWindow);
        actionCDTracks->setObjectName(QString::fromUtf8("actionCDTracks"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionAddfile = new QAction(MainWindow);
        actionAddfile->setObjectName(QString::fromUtf8("actionAddfile"));
        actionAddripped = new QAction(MainWindow);
        actionAddripped->setObjectName(QString::fromUtf8("actionAddripped"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        removeFile = new QPushButton(groupBox);
        removeFile->setObjectName(QString::fromUtf8("removeFile"));

        gridLayout->addWidget(removeFile, 2, 0, 1, 1);

        upFile = new QPushButton(groupBox);
        upFile->setObjectName(QString::fromUtf8("upFile"));

        gridLayout->addWidget(upFile, 2, 1, 1, 1);

        downFile = new QPushButton(groupBox);
        downFile->setObjectName(QString::fromUtf8("downFile"));

        gridLayout->addWidget(downFile, 2, 2, 1, 1);

        tableWidget = new QTableWidget(groupBox);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setMinimumSize(QSize(399, 230));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 3);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tableWidget_2 = new QTableWidget(groupBox_2);
        if (tableWidget_2->columnCount() < 1)
            tableWidget_2->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem1);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setMinimumSize(QSize(399, 220));

        gridLayout_2->addWidget(tableWidget_2, 0, 0, 1, 3);

        removeRippedFile = new QPushButton(groupBox_2);
        removeRippedFile->setObjectName(QString::fromUtf8("removeRippedFile"));

        gridLayout_2->addWidget(removeRippedFile, 1, 0, 1, 1);

        upRippedFile = new QPushButton(groupBox_2);
        upRippedFile->setObjectName(QString::fromUtf8("upRippedFile"));

        gridLayout_2->addWidget(upRippedFile, 1, 1, 1, 1);

        downRippedFile = new QPushButton(groupBox_2);
        downRippedFile->setObjectName(QString::fromUtf8("downRippedFile"));

        gridLayout_2->addWidget(downRippedFile, 1, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        cleanAll = new QPushButton(groupBox_3);
        cleanAll->setObjectName(QString::fromUtf8("cleanAll"));

        gridLayout_3->addWidget(cleanAll, 12, 2, 1, 2);

        durationView = new QLCDNumber(groupBox_3);
        durationView->setObjectName(QString::fromUtf8("durationView"));
        durationView->setMinimumSize(QSize(93, 54));
        durationView->setMaximumSize(QSize(93, 54));

        gridLayout_3->addWidget(durationView, 1, 3, 1, 1);

        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        textBrowser = new QTextBrowser(groupBox_4);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_5->addWidget(textBrowser, 0, 2, 1, 1);


        gridLayout_3->addWidget(groupBox_4, 11, 0, 1, 4);

        manualRename = new QPushButton(groupBox_3);
        manualRename->setObjectName(QString::fromUtf8("manualRename"));

        gridLayout_3->addWidget(manualRename, 12, 0, 1, 2);

        autoRename = new QCheckBox(groupBox_3);
        autoRename->setObjectName(QString::fromUtf8("autoRename"));

        gridLayout_3->addWidget(autoRename, 9, 1, 1, 2);

        startButton = new QPushButton(groupBox_3);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setMaximumSize(QSize(109, 25));

        gridLayout_3->addWidget(startButton, 9, 0, 1, 1);

        stopButton = new QPushButton(groupBox_3);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setMaximumSize(QSize(109, 25));

        gridLayout_3->addWidget(stopButton, 9, 3, 1, 1);

        durationButton = new QPushButton(groupBox_3);
        durationButton->setObjectName(QString::fromUtf8("durationButton"));

        gridLayout_3->addWidget(durationButton, 2, 3, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(94, 54));
        label->setMaximumSize(QSize(94, 54));

        gridLayout_3->addWidget(label, 1, 2, 1, 1);

        albumName = new QLineEdit(groupBox_3);
        albumName->setObjectName(QString::fromUtf8("albumName"));
        albumName->setMaximumSize(QSize(157, 21));

        gridLayout_3->addWidget(albumName, 3, 3, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 3, 2, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 0, 1, 2, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 922, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAddfile);
        menuFile->addAction(actionAddripped);
        menuFile->addAction(actionCDTracks);
        menuFile->addSeparator();
        menuFile->addAction(actionStart);
        menuFile->addAction(actionStop);
        menuFile->addSeparator();
        menuFile->addAction(actionNewProject);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionStart->setText(QApplication::translate("MainWindow", "Convert files", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("MainWindow", "Stop CDRipper", 0, QApplication::UnicodeUTF8));
        actionAdd_file->setText(QApplication::translate("MainWindow", "Add file(s)", 0, QApplication::UnicodeUTF8));
        actionAdd_ripped_file->setText(QApplication::translate("MainWindow", "Add ripped file(s)", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionNewProject->setText(QApplication::translate("MainWindow", "New Project", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionCDTracks->setText(QApplication::translate("MainWindow", "Rip and Add CD Drive tracks", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        actionAddfile->setText(QApplication::translate("MainWindow", "Add files", 0, QApplication::UnicodeUTF8));
        actionAddripped->setText(QApplication::translate("MainWindow", "Add ripped files", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Files to convert", 0, QApplication::UnicodeUTF8));
        removeFile->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        upFile->setText(QApplication::translate("MainWindow", "Up", 0, QApplication::UnicodeUTF8));
        downFile->setText(QApplication::translate("MainWindow", "Down", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Converted files", 0, QApplication::UnicodeUTF8));
        removeRippedFile->setText(QApplication::translate("MainWindow", "Remove", 0, QApplication::UnicodeUTF8));
        upRippedFile->setText(QApplication::translate("MainWindow", "Up", 0, QApplication::UnicodeUTF8));
        downRippedFile->setText(QApplication::translate("MainWindow", "Down", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Toolbar", 0, QApplication::UnicodeUTF8));
        cleanAll->setText(QApplication::translate("MainWindow", "Clean All", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Commandline commands output", 0, QApplication::UnicodeUTF8));
        manualRename->setText(QApplication::translate("MainWindow", "Manual Rename", 0, QApplication::UnicodeUTF8));
        autoRename->setText(QApplication::translate("MainWindow", "Rename files automatically", 0, QApplication::UnicodeUTF8));
        startButton->setText(QApplication::translate("MainWindow", "Convert Files", 0, QApplication::UnicodeUTF8));
        stopButton->setText(QApplication::translate("MainWindow", "Stop CDRipper ", 0, QApplication::UnicodeUTF8));
        durationButton->setText(QApplication::translate("MainWindow", "Calculate duration", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Total duration :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Album name :", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
