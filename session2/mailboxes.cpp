#include <iostream>
#include <set>

using namespace std;

int main()
{
    string s;
    size_t n;
    cin >> n;
    cin >> s;

    // find the smallest unrepeated substr in this string
    set<string> substrs;
    size_t temp_len = 1;
    bool doublon = false;
    size_t best_taille = 0;
    while (temp_len <= n)
    {

        for (size_t i = 0; i < n - temp_len + 1; i++)
        {
            if (substrs.find(s.substr(i, temp_len)) != substrs.end())
            {
                doublon = true;
                break;
            }
            else
            {
                substrs.insert(s.substr(i, temp_len));
            }
        }
        if (!doublon)
        {
            best_taille = temp_len;
            break;
        }
        else
        {
            doublon = false;
            substrs.clear();
        }
        temp_len++;
    }

    // smallest in size
    cout << best_taille << endl;
}