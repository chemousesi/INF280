#include <cstdio>

using namespace std;

int main()
{

    int livres[1005]{0}; // tables des livres et leurs disponnibilié 0 disponible k sera disponible dans k jours

    int nb_clients;
    int nb_jours;
    int nb_livres;
    int id_livre;
    scanf("%d %d\n", &nb_livres, &nb_jours);

    for (int i = 0; i < nb_jours; i++)
    {
        scanf("%d", &nb_clients);
        int duree = 0;
        for (int j = 0; j < nb_clients; j++)
        {

            scanf("%d %d\n", &id_livre, &duree);
            if (livres[id_livre] == 0)
            {
                printf("1\n");
                livres[id_livre] = duree;
            }
            else
            {
                printf("0\n");
            }
        }
        for (int j = 0; j < nb_livres; j++)
        {
            if (livres[j] != 0)
            {
                livres[j] -= 1;
            }
        }
    }

    return 0;
}
