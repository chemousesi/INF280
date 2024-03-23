#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int i = 0;

    while (i < n - 1)
    {
        if (s[i] == s[i + 1])
        {
            s.erase(i, 2);
            n--;
            i = 0;
        }
        else
        {
            i++;
        }
    }
    cout << s << endl;
}