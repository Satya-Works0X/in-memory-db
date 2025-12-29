#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // A record consists of a key and a value stored in memory.
    // DB= HashMap<Key, Value>

    unordered_map<string, string> db;
    string command;
    string key, value;
    // DB part

    while (cin >> command)
    {
        if (command == "INSERT")
        {
            cin >> key >> value;
            db[key] = value;
        }
        else if (command == "GET")
        {
            cin >> key;
            if (db.find(key) != db.end())
            {
                cout << db[key] << endl;
            }
            else
            {
                cout << "Key Not Found" << endl;
            }
        }
        else if (command == "UPDATE")
        {
            cin >> key >> value;
            if (db.find(key) != db.end())
            {
                db[key] = value;
            }
            else
            {
                cout << "Key Not Found" << endl;
            }
        }
        else if (command == "DELETE")
        {
            cin >> key;
            if (db.find(key) != db.end())
            {
                db.erase(key);
            }
            else
            {
                cout << "Key Not Found" << endl;
            }
        }
        else if (command == "EXIT")
        {
            return 0;
        }
    }

    return 0;
}