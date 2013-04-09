//============================================================================
// Name        : epoll_server.cpp
// Author      : AngryPowman
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Common.h"
#include <iostream>
#include "NetService.h"
#include "Config.hpp"
#include <string>
#include "SQLUserStorage.h"
#include "UserManage.hpp"
#include "DBConnection.h"
#include "DBCommand.h"
#include "DBFieldReader.hpp"
#include <ezlogger_headers.hpp>

using namespace std;
using namespace VNOC::Message;

int main(int argc, char* argv[])
{
    Config::getInstance()->Initialize("vnoc.conf");
    cout<<"port:"<<Config::getInstance()->getValue("port")<<endl;
    //sUserStorage us;
    //CUserManage::GetInstance()->initial(&us);
	uint16 port = Config::getInstance()->getValue("port");

    //db test
    DBString dbPath = _DB_TEXT("Database/VNOC.db");
    DBConnection connection(dbPath);
    connection.open();
    if (connection.isAlive())
    {
        cout << "Start DB OK." << endl;

        //localization
        ToT.imbue(locale("chs"));

        // query
        DBCommand cmd(&connection, _DB_TEXT("SELECT guid, nick_name, gender FROM Users;"));
        bool result = cmd.query();
        if (result == true)
        {
            while (cmd.fetchNext())
            {
                const DBFieldReader& guidField = cmd[_DB_TEXT("nick_name")]; 
                ToT << guidField.fieldIndex() << ":" << guidField.fieldName() << " = " << guidField.asString() << endl;
            }
        }

        // execute nonquery command
        cmd.setCommandText(_DB_TEXT("UPDATE Users SET nick_name = ? WHERE guid = ?;"));
        cmd << _DB_TEXT("Ð¡Ãæ×Óex");
        cmd << 10000;
        cmd.execute();
    }


    NetService net;
    net.start(port);

    return 0;
}

#ifdef WIN32
//#include "../../ThirdLibs/VisualLeakDetector/include/vld.h"
#endif
