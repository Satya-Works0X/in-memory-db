#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    // A record consists of a key and a value stored in memory.
    // DB= HashMap<Key, Value>

    unordered_map<string, string> db;
    map<string, string> db_ordered; // For ordered operations if needed
    string command;
    string key, value;
    // DB part

    while (cin >> command)
    {
        if (command == "INSERT")
        {
            cin >> key >> value;
            db_ordered[key] = value;
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
                db_ordered[key] = value;
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
                db_ordered.erase(key);
            }
            else
            {
                cout << "Key Not Found" << endl;
            }
        }
        else if (command == "RANGE")
        {
            string start, end;
            cin >> start >> end;

            auto it = db_ordered.lower_bound(start);
            while (it != db_ordered.end() && it->first <= end)
            {
                cout << it->first << " " << it->second << endl;
                ++it;
            }
        }

        else if (command == "EXIT")
        {
            return 0;
        }
    }

    return 0;
}