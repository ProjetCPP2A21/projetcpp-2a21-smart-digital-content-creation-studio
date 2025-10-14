#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>

class Connection
{
private:
    QSqlDatabase db;

public:
    Connection();
    bool createconnect();   // pour établir la connexion
    void closeconnect();    // pour fermer la connexion
};

#endif // CONNECTION_H
