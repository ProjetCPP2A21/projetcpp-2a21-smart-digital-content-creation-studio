#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class connection
{
private:
    QSqlDatabase db;

public:
    connection();
    bool createconnect(); // ouvre la connexion Oracle (ODBC)
    void closeconnect();  // ferme la connexion
};

#endif // CONNECTION_H
