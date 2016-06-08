#include <iostream>
#include <pqxx/pqxx>
#include <fstream>
#include "json/json.h"
#include "DatabaseService.h"
#include "JsonResolver.h"

using namespace std;
using namespace pqxx;

using namespace std;

int main() {

    string json;
    DatabaseService s;
    s.initConnection("tin", "postgres", "tin", "127.0.0.1", "5432");
    /*s.initOrClearTables();
    while(getline(cin, json)){
        JsonResolver res(json);
        res.execute(&s);
        res.print();
    }*/
    Notification n(0, "cipa na bahamach", "", 1, 0);
    s.addNewNotification(n);



}