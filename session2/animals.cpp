#include <map>
#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;

    map<string, int> animals;

    string animal;
    while (cin >> animal)
    {
        animals[animal]++;
    }

    int nb_predator = -1;
    string save_animal;
    for (auto &animal : animals)
    {
        if (animal.second > nb_predator)
        {
            nb_predator = animal.second;
            save_animal = animal.first;
        }
    }

    int sum_of_others = 0;
    for (auto animal : animals)
    {
        if (animal.first != save_animal)
        {
            sum_of_others += animal.second;
        }
    }

    if (sum_of_others < nb_predator)
    {
        cout << save_animal << endl;
    }
    else
    {
        cout << "NONE" << endl;
    }
}