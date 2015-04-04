#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "htmlpaser.h"

#include <QDebug>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QMessageBox>
#include <QTextCodec>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->findButton->setShortcut(QKeySequence::InsertParagraphSeparator);
    ui->findButton->setShortcut(Qt::Key_Enter);
    ui->findButton->setShortcut(Qt::Key_Return);
    ui->lineEdit->setFocus();
    network_manager_sougou = new QNetworkAccessManager(this);
}

MainWindow::~MainWindow()
{
    //
    delete ui;
}

void MainWindow::on_findButton_clicked()
{

    QFile *file = new QFile("/home/duanbangchao/workspace/QT/build-AmyMp3Downloader-Desktop-Debug/index.html");
    if(file->open(QIODevice::ReadOnly)){
    HtmlPaser *parser = new  HtmlPaser(file->readAll());
    qDebug()<<file->readAll()<<endl;

    delete parser;
    file->close();
    }
//    QString keyword = ui->lineEdit->text().trimmed();
//    if(keyword.isEmpty()){
//        QMessageBox::warning(this,tr("提示信息"),tr("请输入需要搜索歌曲的名称"));
//        return;
//    }
//    network_manager_sougou->get(QNetworkRequest(QUrl("http://mp3.sogou.com/music.so?query="+keyword)));
//    connect(network_manager_sougou,SIGNAL(finished(QNetworkReply*)),  //关联信号和槽
//                this,SLOT(search_sougou_music_end(QNetworkReply*)));
//    connect(network_manager_sougou,SIGNAL(readyRead()),this,SLOT(search_sougou_music_readyRead));
//    connect(network_manager_sougou,SIGNAL(downloadProgress(qint64, qint64)),this,SLOT(updateDataReadProgress(qint64, qint64)));

//    ui->progressBar->setValue(0);
}

void MainWindow::search_sougou_music_end(QNetworkReply *reply){
     // Reading attributes of the reply
     // e.g. the HTTP status code
     QVariant statusCodeV =
     reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
     // Or the target URL if it was a redirect:
     QVariant redirectionTargetUrl =
     reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
     // see CS001432 on how to handle this

//     QByteArray arr = reply->readAll();
//     char *data = arr.data();
//     qDebug()<<reply->readAll()<<endl;

     // no error received?
     if (reply->error() == QNetworkReply::NoError)
     {
         // read data from QNetworkReply here

         // Example 1: Creating QImage from the reply
         //QImageReader imageReader(reply);
         //QImage pic = imageReader.read();

         // Example 2: Reading bytes form the reply
         QFile *file = new QFile("index.html");

         if(file->exists()){
             file->remove();
         }

         if(!file->open(QIODevice::WriteOnly)){
             delete file;
             return;
         }else{
//             QTextCodec *codec = QTextCodec::codecForName("gbk");
//             QString all = codec->toUnicode(reply->readAll());
//             QTextStream out(file);

//             out<< reply->readAll();
             file->write(reply->readAll());

             file->close();
         }
     }
     // Some http error received
     else
     {
         // handle errors here
     }

     // We receive ownership of the reply object
     // and therefore need to handle deletion.
     reply->deleteLater();
}

void MainWindow::search_sougou_music_readyRead(){
    qDebug()<<"readyRead"<<endl;
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes){
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}
