/********************************************************************************
** Form generated from reading UI file 'SerialConfigWindow.ui'
**
** Created: Mon Oct 25 13:40:44 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALCONFIGWINDOW_H
#define UI_SERIALCONFIGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialConfigWindow
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *labelPort;
    QComboBox *comboBoxPort;
    QLabel *labelBaud;
    QComboBox *comboBoxBaud;
    QLabel *labelData;
    QComboBox *comboBoxData;
    QLabel *labelStop;
    QComboBox *comboBoxStop;
    QLabel *labelParity;
    QComboBox *comboBoxParity;

    void setupUi(QDialog *SerialConfigWindow)
    {
        if (SerialConfigWindow->objectName().isEmpty())
            SerialConfigWindow->setObjectName(QString::fromUtf8("SerialConfigWindow"));
        SerialConfigWindow->resize(269, 240);
        SerialConfigWindow->setMinimumSize(QSize(269, 240));
        SerialConfigWindow->setMaximumSize(QSize(269, 240));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/server_connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        SerialConfigWindow->setWindowIcon(icon);
        SerialConfigWindow->setModal(true);
        buttonBox = new QDialogButtonBox(SerialConfigWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(90, 210, 176, 27));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(SerialConfigWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(12, 12, 251, 181));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setLabelAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelPort = new QLabel(widget);
        labelPort->setObjectName(QString::fromUtf8("labelPort"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelPort->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelPort);

        comboBoxPort = new QComboBox(widget);
        comboBoxPort->setObjectName(QString::fromUtf8("comboBoxPort"));
        comboBoxPort->setFrame(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxPort);

        labelBaud = new QLabel(widget);
        labelBaud->setObjectName(QString::fromUtf8("labelBaud"));
        labelBaud->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, labelBaud);

        comboBoxBaud = new QComboBox(widget);
        comboBoxBaud->setObjectName(QString::fromUtf8("comboBoxBaud"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxBaud);

        labelData = new QLabel(widget);
        labelData->setObjectName(QString::fromUtf8("labelData"));
        labelData->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, labelData);

        comboBoxData = new QComboBox(widget);
        comboBoxData->setObjectName(QString::fromUtf8("comboBoxData"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxData);

        labelStop = new QLabel(widget);
        labelStop->setObjectName(QString::fromUtf8("labelStop"));
        labelStop->setFont(font);

        formLayout->setWidget(3, QFormLayout::LabelRole, labelStop);

        comboBoxStop = new QComboBox(widget);
        comboBoxStop->setObjectName(QString::fromUtf8("comboBoxStop"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBoxStop);

        labelParity = new QLabel(widget);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        labelParity->setFont(font);

        formLayout->setWidget(4, QFormLayout::LabelRole, labelParity);

        comboBoxParity = new QComboBox(widget);
        comboBoxParity->setObjectName(QString::fromUtf8("comboBoxParity"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxParity);


        retranslateUi(SerialConfigWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), SerialConfigWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SerialConfigWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(SerialConfigWindow);
    } // setupUi

    void retranslateUi(QDialog *SerialConfigWindow)
    {
        SerialConfigWindow->setWindowTitle(QApplication::translate("SerialConfigWindow", "SerialConfigWindow", 0, QApplication::UnicodeUTF8));
        labelPort->setText(QApplication::translate("SerialConfigWindow", "Port:", 0, QApplication::UnicodeUTF8));
        labelBaud->setText(QApplication::translate("SerialConfigWindow", "Baud Rate:", 0, QApplication::UnicodeUTF8));
        labelData->setText(QApplication::translate("SerialConfigWindow", "Data Bits:", 0, QApplication::UnicodeUTF8));
        labelStop->setText(QApplication::translate("SerialConfigWindow", "Stop Bits:", 0, QApplication::UnicodeUTF8));
        labelParity->setText(QApplication::translate("SerialConfigWindow", "Parity:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SerialConfigWindow: public Ui_SerialConfigWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALCONFIGWINDOW_H
