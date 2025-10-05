#include "mainwindow.h"
#include <QApplication>
#include <QtWidgets/QMainWindow>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("QWidget { background-color: white; color: black; }" "QWidget {font-family: 'Roboto';}" "QLabel { background: transparent; color: #EDEAF9; }"
                    "QLabel#formTitle { color:#ffaa00; font-weight:800; font-size:18px; padding-left:6px; }"
                    "QGroupBox { background:#1B2040; border:1px solid #6B6FB0; border-radius:12px; margin-top:6px; }"
                    "QLineEdit, QComboBox, QDateEdit, QTextEdit { background:#23284F; color:#FFFFFF; border:1px solid #6B6FB0; border-radius:8px; padding:8px 10px; }"
                    "QLineEdit#leSearch { background:#3B2B67; border:1px solid #8D77CC; }"
                    "QTableWidget { background:#1A1F3D; color:#F2F2FA; gridline-color:#40467A; alternate-background-color:#232B57; }"
                    "QHeaderView::section { background:#12163A; color:#D2B7FF; padding:10px; border:none; }");
    MainWindow w;
    w.show();
    return a.exec();
}
