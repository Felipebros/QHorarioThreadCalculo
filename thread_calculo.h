#ifndef THREAD_CALCULO_H
#define THREAD_CALCULO_H

#include <QThread>

class Thread_calculo : public QThread
{
    Q_OBJECT
public:
    explicit Thread_calculo(QObject *parent = nullptr);
    QString HORARIO;
signals:
    void concluido(QString);
protected:
    void run() override;
};

#endif // THREAD_CALCULO_H
