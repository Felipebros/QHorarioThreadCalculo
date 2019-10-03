#include "thread_calculo.h"
#include <QTime>
#include <QDebug>

Thread_calculo::Thread_calculo(QObject *parent)
    : QThread(parent)
{

}

void Thread_calculo::run()
{
    for (int i = 0; i < 3; ++i) {
        qDebug() << QTime::currentTime().toString() << "etapa" << i;
//        sleep(1);
        msleep(100);
        emit concluido(QString::number(i) + " " + HORARIO + " - " +
                       QTime::currentTime().toString());
    }
}
