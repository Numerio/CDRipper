/********************************************************************************
** Form generated from reading UI file 'ripsettings.ui'
**
** Created: Tue Jan 17 20:30:49 2012
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RIPSETTINGS_H
#define UI_RIPSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_RipSettings
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;

    void setupUi(QDialog *RipSettings)
    {
        if (RipSettings->objectName().isEmpty())
            RipSettings->setObjectName(QString::fromUtf8("RipSettings"));
        RipSettings->resize(400, 300);
        buttonBox = new QDialogButtonBox(RipSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(RipSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 361, 271));

        retranslateUi(RipSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), RipSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RipSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(RipSettings);
    } // setupUi

    void retranslateUi(QDialog *RipSettings)
    {
        RipSettings->setWindowTitle(QApplication::translate("RipSettings", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("RipSettings", "Settings", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RipSettings: public Ui_RipSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RIPSETTINGS_H
