#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Oracle in XE};Dbq=XE;Uid=adem;Pwd=0000;");



/*db.setDatabaseName("aaa");//inserer le nom de la source de données
db.setUserName("test");//inserer nom de l'utilisateur
db.setPassword("0000");//inserer mot de passe de cet utilisateur
*/
if (db.open())
test=true;

else qDebug() << db.lastError().text();




    return  test;
}
