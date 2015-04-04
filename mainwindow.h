#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_findButton_clicked();
    void search_sougou_music_end(QNetworkReply* reply);
    void search_sougou_music_readyRead();
    void updateDataReadProgress(qint64 bytesRead, qint64 totalBytes);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *network_manager_sougou;
};

#endif // MAINWINDOW_H
