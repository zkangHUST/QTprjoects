/********************************************************************************
** Form generated from reading UI file 'find.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIND_H
#define UI_FIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_find
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *find)
    {
        if (find->objectName().isEmpty())
            find->setObjectName(QStringLiteral("find"));
        find->resize(450, 120);
        find->setMinimumSize(QSize(450, 120));
        find->setMaximumSize(QSize(450, 120));
        find->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(find);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(find);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(find);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        pushButton = new QPushButton(find);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox = new QCheckBox(find);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout->addWidget(checkBox);

        checkBox_2 = new QCheckBox(find);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout->addWidget(checkBox_2);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pushButton_2 = new QPushButton(find);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_2->addWidget(pushButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(find);

        QMetaObject::connectSlotsByName(find);
    } // setupUi

    void retranslateUi(QDialog *find)
    {
        find->setWindowTitle(QApplication::translate("find", "Dialog", nullptr));
        label->setText(QApplication::translate("find", "Find What", nullptr));
        pushButton->setText(QApplication::translate("find", "Find", nullptr));
        checkBox->setText(QApplication::translate("find", "Match case", nullptr));
        checkBox_2->setText(QApplication::translate("find", "Search backward", nullptr));
        pushButton_2->setText(QApplication::translate("find", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class find: public Ui_find {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIND_H
