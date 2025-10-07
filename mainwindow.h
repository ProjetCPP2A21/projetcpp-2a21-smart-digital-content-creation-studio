#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addProjectButton_clicked();
    void on_deleteProjectButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
