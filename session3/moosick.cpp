#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int n, c;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> c;

    vector<int> seventh_cord_ref;

    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        seventh_cord_ref.push_back(temp);
    }
    sort(seventh_cord_ref.begin(), seventh_cord_ref.end());

    return 0;
}

vector<int> solve(int n, int c, int arr[])
{

    // rchercher les 7eme cordes dans une liste de notes, chercher les c notes qui sont soit permuté ou à une difference pres

    vector<int> seventh_cord_ref;
    int i = 0, j = c - 1;
    // parcours de la liste de notes
    while (i <= n - c)
    {
        vector<int> window = get_window(i, c, arr);
        if (is_seventh_cord(window))
        {
            seventh_cord_ref.push_back(i);
        }
        i++;
    }
}

vector<int> get_window(int pos, int window_size, int arr[])
{
    vector<int> window;
    for (int i = pos; i < window_size + pos; i++)
    {
        window.push_back(arr[i]);
    }
    return window;
}

bool is_seventh_cord(vector<int> window, vector<int> seventh_cord_ref)
{
    // trier la liste
    sort(window.begin(), window.end());
    // verifier si la liste est une permutation de la liste de reference

    // verifier si la difference entre chaque note est soit 3 ou 4
    for (int i = 0; i < window.size() - 1; i++)
    {
        if (window[i + 1] - window[i] != 3 && window[i + 1] - window[i] != 4)
        {
            return false;
        }
    }
    return true;
}