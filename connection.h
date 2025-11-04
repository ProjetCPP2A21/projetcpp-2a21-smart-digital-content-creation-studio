#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

class Connection
{
public:
    Connection();
    bool createconnect(); // crée la connexion à la base
    QSqlDatabase getDatabase(); // obtenir la connexion
};

#endif // CONNECTION_H
