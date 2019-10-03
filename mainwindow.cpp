#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>

#include "thread_calculo.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_nam(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionSair_triggered()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::on_btn_atualizar_clicked()
{
    //    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request;
    request.setUrl(QUrl(ui->ln_servidor->text()));
    request.setHeader(QNetworkRequest::ContentTypeHeader, QLatin1String(
                          "application/json"));
    //    request.setRawHeader("User-Agent", "MyOwnBrowser 1.0");

    QJsonObject dados_local{
        {"teste", "teste"}
    };
    //    QNetworkReply *reply = m_nam->post(request, QJsonDocument(dados_local).toJson());
    QNetworkReply *reply = m_nam->get(request);
    mThread_calculo = new Thread_calculo(this);
    connect(mThread_calculo, &Thread_calculo::concluido, [&](QString msg) {
        qDebug() << QTime::currentTime().toString() << msg;
    });

    connect(reply, &QNetworkReply::finished, this,
            &MainWindow::slotFinished);
    //    connect(m_nam, &QNetworkAccessManager::finished, this,
    //            &MainWindow::slotFinished);
    connect(reply, &QIODevice::readyRead, this,
            &MainWindow::slotReadyRead);
    connect(reply,
            QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
            this, &MainWindow::slotError);
    connect(reply, &QNetworkReply::sslErrors,
            this, &MainWindow::slotSslErrors);
}

void MainWindow::slotFinished()
{
    QNetworkReply * reply = qobject_cast<QNetworkReply *>(sender());
    reply->deleteLater();

    ui->lbl_horas->setText(reply->readAll());
    mThread_calculo->HORARIO = ui->lbl_horas->text();
    mThread_calculo->start();
            qDebug() << reply->readAll();
    //    const QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    //    const QJsonObject obj = doc.object();

    //    if (obj.isEmpty()) {
    //        qDebug() << obj;
    //    }
    qDebug() << "slot Finished";
}

void MainWindow::slotReadyRead()
{
    qDebug() << "slot Ready Read";
}

void MainWindow::slotError()
{
    qDebug() << "slot Error";
}

void MainWindow::slotSslErrors()
{
    qDebug() << "slot Error SSL";
}
