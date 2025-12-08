#ifndef ARDUINO_MANAGER_H
#define ARDUINO_MANAGER_H

#include <QObject>
#include <QSerialPort>

class ArduinoManager : public QObject
{
    Q_OBJECT

public:
    explicit ArduinoManager(QObject *parent = nullptr);
    bool connectArduino(const QString &portName = "COM9");
    void sendCommand(const QString &cmd);

signals:
    void duplicateDetected();
    void noDuplicate();
    void enrollOk();
    void enrollFail();
    void fingerId(int id);
    void captureError(QString msg);
    void clearDbOk();
    void clearDbFail();
    void messageReceived(QString msg);

private slots:
    void readData();

private:
    QSerialPort *serial;
    QString buffer;
};

#endif // ARDUINO_MANAGER_H
