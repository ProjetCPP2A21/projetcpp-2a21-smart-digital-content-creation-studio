#include "mainwindow.h"
#include "connection.h"
#include <QMessageBox>
#include <QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection& c= Connection::createInstance();
    bool test=c.createconnect();
    MainWindow w;
    a.setStyleSheet("QWidget { background-color: white; color: black; }" "QWidget {font-family: 'Roboto';}"
                    "QLabel {background: transparent;}"
                    "QLabel#formTitle { color:#ffaa00; font-weight:800; font-size:18px; padding-left:6px; }"
                    "QGroupBox { background:#1B2040; border:1px solid #6B6FB0; border-radius:12px; margin-top:6px; }"
                    "QLineEdit, QComboBox, QDateEdit, QTextEdit { background:#23284F; color:#FFFFFF; border:1px solid #6B6FB0; border-radius:8px; }"
                    "QLineEdit#leSearch { background:#3B2B67; border:1px solid #8D77CC; }"
                    "QTableWidget { background:#1A1F3D; color:#F2F2FA; gridline-color:#40467A; alternate-background-color:#232B57; }"
                    "QHeaderView::section { background:#12163A; color:#D2B7FF; padding:10px; border:none; }"
                    "QMessageBox {"
                    " background-color: #FFFFFF;"          // fond blanc épuré
                    " border: 1px solid #C0C0C0;"         // bordure fine grise
                    " border-radius: 10px;"                // coins arrondis
                    " padding: 10px;"
                    " font-family: 'Segoe UI', 'Arial', sans-serif;"
                    " font-size: 14px;"
                    " color: #333333;"
                    "}"

                    // Style du texte
                    "QMessageBox QLabel {"
                    " color: #333333;"
                    " font-size: 14px;"
                    "}"

                    // Style des boutons
                    "QMessageBox QPushButton {"
                    " background-color: #6A0DAD;"         // mauve doux
                    " color: white;"
                    " border-radius: 6px;"
                    " padding: 8px 16px;"
                    " font-weight: bold;"
                    " min-width: 80px;"
                    "}"

                    "QMessageBox QPushButton:hover {"
                    " background-color: #8A2BE2;"         // mauve plus clair au survol
                    "}"

                    "QMessageBox QPushButton:pressed {"
                    " background-color: #4B0082;"         // mauve foncé à l'appui
                    "}");

    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                 QObject::tr("connection successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
