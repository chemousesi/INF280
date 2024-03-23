#include <numeric>
#include <iostream>
#include <set>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{

    unordered_set<string> monuments;

    string monument;
    // read thewhole line

    while (getline(cin, monument))
    {
        string temp = monument.substr(11, monument.size() - 10);
        // cout << temp << "size " << temp.size() << endl;
        monuments.insert(temp);
    }
    cout << monuments.size() << endl;
}