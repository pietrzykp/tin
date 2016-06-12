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

    string json, deviceId, action;
    DatabaseService s;
    s.initConnection("tin", "postgres", "tin", "127.0.0.1", "5432");
    while(getline(cin, json)){
        getline(cin, deviceId);
        getline(cin, action);
        if(json == "newNotif") {
            string i;
            string str;
            getline(cin, i);
            getline(cin, str);
            Notification n(0, str, "", atoi(i.c_str()), 0);
            s.addNewNotification(n);
            continue;
        }
        JsonResolver res(atoi(action.c_str()), atoi(deviceId.c_str()), json);
        res.execute(&s);
        res.print();
    }



}