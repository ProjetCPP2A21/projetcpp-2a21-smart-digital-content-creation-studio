#ifndef ARDUINO_H
#define ARDUINO_H

#include <QSerialPort>
#include <QSerialPortInfo>

class Arduino
{
private:
    QSerialPort *serial;   // pointeur vers l’objet QSerialPort
    QString arduino_port_name;
    QByteArray data;       // données lues depuis arduino

    static const quint16 arduino_uno_vendor_id = 9025;    // IDs officiels Arduino
    static const quint16 arduino_uno_product_id = 67;

    bool arduino_is_available;

public:
    Arduino();
    QString getarduino_port_name();
    QSerialPort* getserial();

    int connect_arduino();
    int close_arduino();

    QByteArray read_from_arduino();
    void write_to_arduino(QByteArray);
};

#endif // ARDUINO_H
