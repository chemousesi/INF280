#include <iostream>

using namespace std;
void count_occurences(string s, int nb_occurences_lettres[]);
bool equal_occurences(int reference_occurences_lettres[], int nb_occurences_lettres[]);

int main()
{

    int len_s, len_t;
    cin >> len_s >> len_t;

    string s, t;
    cin >> s >> t;

    int nb_occurences_lettres[52]{0};
    int reference_occurences_lettres[52]{0};

    count_occurences(s, reference_occurences_lettres);
    count_occurences(t.substr(0, len_s), nb_occurences_lettres);

    // sliding window
    int count = 0;
    int i = 0;
    while (i <= len_t - len_s)
    {
        if (equal_occurences(reference_occurences_lettres, nb_occurences_lettres))
            count++;
        if (t[i] >= 'a' && t[i] <= 'z')
        {
            nb_occurences_lettres[t[i] - 'a']--;
        }
        else if (t[i] >= 'A' && t[i] <= 'Z')
        {
            nb_occurences_lettres[t[i] - 'A' + 26]--;
        }
        if (t[i + len_s] >= 'a' && t[i + len_s] <= 'z')
        {
            nb_occurences_lettres[t[i + len_s] - 'a']++;
        }
        else if (t[i + len_s] >= 'A' && t[i + len_s] <= 'Z')
        {
            nb_occurences_lettres[t[i + len_s] - 'A' + 26]++;
        }
        i++;
    }
    cout << count << endl;
}

void count_occurences(string s, int nb_occurences_lettres[])
{
    for (int i = 0; i < 52; i++)
    {
        nb_occurences_lettres[i] = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            nb_occurences_lettres[s[i] - 'a']++;
        }
        else
        {
            nb_occurences_lettres[s[i] - 'A' + 26]++;
        }
    }
}

bool equal_occurences(int reference_occurences_lettres[], int nb_occurences_lettres[])
{
    for (int i = 0; i < 52; i++)
    {
        if (reference_occurences_lettres[i] != nb_occurences_lettres[i])
        {
            return false;
        }
    }
    return true;
}