#include <iostream>
#include <string>
#include "mydb.h"

int main(){
    CMYDB my;
    my.initDB("localhost" , "root", "" , "test" );
    my.executeSQL("select * from category;");
    return 0;
}