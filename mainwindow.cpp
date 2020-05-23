#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    std::vector<std::string> str_rotor;

    try{
        str_rotor.push_back(std::string("EKMFLGDQVZNTOWYHXUSPAIBRCJ"));
        str_rotor.push_back(std::string("AJDKSIRUXBLHWTMCQGZNPYFVOE"));
        str_rotor.push_back(std::string("BDFHJLCPRTXVZNYEIWGAKMUSQO"));

    } catch (std::string ex){
        std::cout << ex;
    }

//    Reflector ref(std::string("AY BR CU DH EQ FS GL IP JX KN MO TZ VW"));
    std::string refl("AY BR CU DH EQ FS GL IP JX KN MO TZ VW");
    en = new Encrypter(str_rotor, refl);
//    for(auto const& position : )

    en->print();
    ui->setupUi(this);
//    QObject::connect(&a, &Counter::valueChanged,
//                         &b, &Counter::setValue);


//    en->setPosition("rvc");
     en->setPosition("aaa");


    ui->label_2->setText(QString(en->getChar(0)).toUpper());
    ui->label_3->setText(QString(en->getChar(1)).toUpper());
    ui->label_4->setText(QString(en->getChar(2)).toUpper());
}

MainWindow::~MainWindow()
{
    delete en;
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    en->rotate(0);
    ui->label_2->setText(QString(en->getChar(0)).toUpper());
}

void MainWindow::on_pushButton_4_clicked()
{
    en->rotate(1);
    ui->label_3->setText(QString(en->getChar(1)).toUpper());

}

void MainWindow::on_pushButton_5_clicked()
{
    en->rotate(2);
    ui->label_4->setText(QString(en->getChar(2)).toUpper());
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    if(arg1.size() - ui->textEdit->toPlainText().size() == 1) {
        ui->textEdit->setText(ui->textEdit->toPlainText() + QChar(en->encrypt(arg1.toStdString().at(arg1.size()-1))));
    } else
        if(ui->textEdit->toPlainText().size() - arg1.size() == 1) {
            en->rotateBack();
            ui->textEdit->setText(ui->textEdit->toPlainText().left(ui->textEdit->toPlainText().size() - 1));

    } else {
        ui->textEdit->setText(arg1);
    }

    ui->label_2->setText(QString(en->getChar(0)).toUpper());
    ui->label_3->setText(QString(en->getChar(1)).toUpper());
    ui->label_4->setText(QString(en->getChar(2)).toUpper());
}

void MainWindow::on_pushButton_clicked()
{
    en->rotateBack(0);
    ui->label_2->setText(QString(en->getChar(0)).toUpper());

}

void MainWindow::on_pushButton_3_clicked()
{
    en->rotateBack(1);
    ui->label_3->setText(QString(en->getChar(1)).toUpper());
}

void MainWindow::on_pushButton_6_clicked()
{
    en->rotateBack(2);
    ui->label_4->setText(QString(en->getChar(2)).toUpper());
}
