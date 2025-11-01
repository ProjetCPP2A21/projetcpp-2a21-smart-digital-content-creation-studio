#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class connection
{
private:
    QSqlDatabase db;

    // Constructeur privé pour empêcher la création multiple
    connection();

public:
    // Accès global à l’unique instance
    static connection& getInstance();

    // Méthodes de connexion
    bool createconnect();
    void closeconnect();

    // Empêche la copie et l'affectation
    connection(const connection&) = delete;
    connection& operator=(const connection&) = delete;
};

#endif // CONNECTION_H
