#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QtGui>
#include <QPushButton>
#include <QTextStream>
#include <QXmlStreamReader>
#include <QFileDialog>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton*label = new QPushButton(this);
    QPushButton*label2 = new QPushButton(this);
    label->setText("Notepad");
    label2->setText("Excel");
    label->move(100,100);
    label2->move(100,200);
    label->clicked();
    label2->clicked();
    connect(label, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(label2, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    QFile inFile;
    inFile.setFileName("C://Users//joses//C++_GUI//First_Project//static_links.xml");

        if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
        }

        QXmlStreamReader xmlReader(&inFile);
        QString text_to_run;
        while(!xmlReader.atEnd())
        {
            xmlReader.readNext();

            if (!xmlReader.isStartElement()) {
                continue;
            }

            QString text = xmlReader.name().toString();
            if ( (text == QStringLiteral("notepad")) )
            {
                text_to_run = xmlReader.readElementText();

            }
        }
    QString q1 = text_to_run + QStringLiteral(" & exit");
    system(qPrintable(q1));
}
void MainWindow::on_pushButton_clicked2(){
    QFile inFile;
    inFile.setFileName("C://Users//joses//C++_GUI//First_Project//static_links.xml");

        if (!inFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
        }

        QXmlStreamReader xmlReader(&inFile);
        QString text_to_run;
        while(!xmlReader.atEnd())
        {
            xmlReader.readNext();

            if (!xmlReader.isStartElement()) {
                continue;
            }

            QString text = xmlReader.name().toString();
            if ( (text == QStringLiteral("Excel")) )
            {
                text_to_run = xmlReader.readElementText();

            }
        }
    QString q1 = text_to_run + QStringLiteral(" & exit");
    system(qPrintable(q1));
}
