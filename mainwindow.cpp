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
    label->setText("Notepad");
    label->move(100,100);
    label->clicked();
    connect(label, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
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
    system(qPrintable(text_to_run));
}
