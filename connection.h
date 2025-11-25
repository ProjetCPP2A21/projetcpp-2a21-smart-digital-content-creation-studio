#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
private:
    QSqlDatabase db;
    Connection(); // Constructeur privé pour singleton

public:
    // Empêcher la copie
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

    // Méthode singleton
    static Connection& getInstance();

    // Méthodes de connexion
    bool createconnect();
    void closeconnect();
    QSqlDatabase getDatabase();
};

#endif // CONNECTION_H
