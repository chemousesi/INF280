#include <iostream>

using namespace std;

int grenouille_en_tete(int *grenouilles, int nbGrenouilles);

int main()
{

    int nbGrenouilles;
    int nbTours;

    cin >> nbGrenouilles;
    cin >> nbTours;

    int duree_en_tete[nbGrenouilles + 1];
    int grenouilles[nbGrenouilles + 1];
    int championne = 0;
    for (int i = 0; i < nbGrenouilles + 1; i++)
    {
        duree_en_tete[i] = 0;
        grenouilles[i] = 0;
    }

    for (int i = 1; i < nbTours; i++)
    // strictement en tete dans le plus gand nombre de tours

    {
        int grenouille, saut;
        cin >> grenouille >> saut;
        grenouilles[grenouille] += saut;

        int championne = grenouille_en_tete(grenouilles, nbGrenouilles);
        if (championne != -1)
        {
            duree_en_tete[championne]++;
        }
    }

    // chercher la grenouille qui a passer le plus de temps en tete
    int max_duree_grenouille = 0;
    for (int i = 1; i < nbGrenouilles + 1; i++)
    {
        if (duree_en_tete[i] > duree_en_tete[max_duree_grenouille])
        {
            max_duree_grenouille = i;
        }
    }

    cout << max_duree_grenouille << endl;
    return 0;
}

int grenouille_en_tete(int *grenouilles, int nbGrenouilles)
{
    int grenouille_en_tete = 0;
    int d_max = -1;
    bool alone = true;

    for (int i = 1; i < nbGrenouilles + 1; i++)
    {
        if (grenouilles[i] == grenouilles[grenouille_en_tete])
        {
            alone = false;
        }
        else if (grenouilles[i] > grenouilles[grenouille_en_tete])
        {
            grenouille_en_tete = i;
            alone = true;
        }

        if (alone == true)
            return grenouille_en_tete;
        else
            return -1;
    }
    return grenouille_en_tete;
}