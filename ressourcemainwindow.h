#ifndef RESSOURCEMAINWINDOW_H
#define RESSOURCEMAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui { class ressourceMainWindow; }
QT_END_NAMESPACE

class ressourceMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ressourceMainWindow(QWidget *parent = nullptr);
    ~ressourceMainWindow();

private slots:
    void on_AjoutRess_clicked();
    void on_ModifieRess_clicked();
    void on_SupprimerRess_clicked();
    void on_PDFRess_clicked();
    void on_StatistiqueRess_clicked();
    void on_ImpBut_clicked();
    void on_RechercheRess_textChanged(const QString &text);
    void on_RessourceTab_clicked(const QModelIndex &index);
    void filterTable();
    void on_RessourceTab_doubleClicked(const QModelIndex &index);


private:
    Ui::ressourceMainWindow *ui;
    QString currentFilePath;
    qint64 currentFileSize = 0;
    void highlightSearchResults(const QString &text);
    void refreshTable();
    void updateStats();
    void clearForm();
    void loadFilePreview(const QString &path);
    QString generateNextId();
};

#endif // RESSOURCEMAINWINDOW_H
