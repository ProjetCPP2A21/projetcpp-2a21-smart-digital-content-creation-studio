#include "arduino_manager.h"
#include <QDebug>

ArduinoManager::ArduinoManager(QObject *parent)
    : QObject(parent), serial(new QSerialPort(this))
{
}

bool ArduinoManager::connectArduino(const QString &portName)
{
    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::Baud9600);

    if (!serial->open(QIODevice::ReadWrite)) {
        qDebug() << "Impossible d'ouvrir le port Arduino!";
        return false;
    }

    connect(serial, &QSerialPort::readyRead,
            this, &ArduinoManager::readData);

    qDebug() << "Arduino connecté sur" << portName;
    return true;
}

void ArduinoManager::sendCommand(const QString &cmd)
{
    if (serial && serial->isOpen()) {
        serial->write(cmd.toUtf8());
        serial->write("\n");
    }
}

void ArduinoManager::readData()
{
    buffer += serial->readAll();

    // Tant qu’on trouve une ligne complète, on la traite
    int index;
    while ((index = buffer.indexOf('\n')) != -1)
    {
        QString msg = buffer.left(index).trimmed();
        buffer.remove(0, index + 1);

        if (msg.isEmpty()) continue;

        // --- Doublon ---
        if (msg == "DUPLICATE") emit duplicateDetected();
        else if (msg == "NO_DUPLICATE") emit noDuplicate();

        // --- Enroll ---
        else if (msg == "ENROLL_OK") emit enrollOk();
        else if (msg == "ENROLL_FAIL") emit enrollFail();

        // --- Scan ---
        else if (msg.startsWith("FINGER_ID:")) {
            int id = msg.mid(11).toInt();
            emit fingerId(id);
        }

        // --- Effacer DB ---
        else if (msg == "DB_CLEARED") emit clearDbOk();
        else if (msg == "DB_CLEAR_FAIL") emit clearDbFail();

        // --- Erreurs scan/enroll ---
        else if (msg == "NOT_FOUND" ||
                 msg == "SCAN_FAIL" ||
                 msg == "TIMEOUT" ||
                 msg == "CVP") {
            emit captureError(msg);
        }

        // --- Messages informatifs ---
        else if (msg == "READY" ||
                 msg == "PLACE_FINGER_1" ||
                 msg == "PLACE_FINGER_2" ||
                 msg == "PLACE_FINGER_SCAN" ||
                 msg == "PLACE_FINGER_DUP") {
            qDebug() << "Arduino:" << msg;
        }

        // --- Inconnu ---
        else {
            emit messageReceived(msg);
            qDebug() << "Arduino message inconnu :" << msg;
        }
    }
}
