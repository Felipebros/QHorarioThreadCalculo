#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//#include <QObject>
//#include <QNetworkRequest>
//#include <QNetworkAccessManager>
//#include <QNetworkReply>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
//class QNetworkReply;
QT_END_NAMESPACE

class QNetworkAccessManager;
class Thread_calculo;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotReadyRead();
    void slotError();
    void slotSslErrors();
    void slotFinished();
private slots:
    void on_actionSair_triggered();

    void on_pushButton_clicked();

    void on_btn_atualizar_clicked();

private:

    Ui::MainWindow *ui;
    QNetworkAccessManager *m_nam;
    Thread_calculo *mThread_calculo;

//    QNetworkAccessManager::Operation m_method;
//    QNetworkRequest m_request;
};
#endif // MAINWINDOW_H
