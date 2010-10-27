/********************************************************************************
** Form generated from reading UI file 'Teste.ui'
**
** Created: Mon Oct 25 13:40:44 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTE_H
#define UI_TESTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Teste
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Teste)
    {
        if (Teste->objectName().isEmpty())
            Teste->setObjectName(QString::fromUtf8("Teste"));
        Teste->resize(400, 300);
        buttonBox = new QDialogButtonBox(Teste);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Teste);
        QObject::connect(buttonBox, SIGNAL(accepted()), Teste, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Teste, SLOT(reject()));

        QMetaObject::connectSlotsByName(Teste);
    } // setupUi

    void retranslateUi(QDialog *Teste)
    {
        Teste->setWindowTitle(QApplication::translate("Teste", "Teste", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Teste: public Ui_Teste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTE_H
