#ifndef _MY_DB_H
#define _MY_DB_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <mysql/mysql.h>
using namespace std;
class CMYDB{
public:
    CMYDB();
    bool initDB(string server_host, string user, string password, string db_name);
    bool executeSQL(string sql_str);
    bool create_table(string table_str_sql);
    ~CMYDB();
private:
    MYSQL *connection;
    MYSQL_RES *res;
    MYSQL_ROW row;
};
#endif