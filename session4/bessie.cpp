#include <iostream>

using namespace std;

int wins(int i, int k, int jeu, int acc);
int gagne(int j1, int j2);
int a[100005];
long long N, K;

const int H = 0;
const int P = 1;
const int S = 2;

int main()
{
    // H=0 P=1 S=2
    cin >> N >> K;

    for (int i = 1; i < N + 1; i++)
    {
        char c;
        cin >> c;
        if (c == 'H')
            a[i] = H;
        if (c == 'P')
            a[i] = P;
        if (c == 'S')
            a[i] = S;
    }

    int tab[N][K][3];

    for (long long i = 1; i < N + 1, i++)
    {
        for (long long j = 1; j < K + 1, j++)
        {
            for (int g = 1; g < 3, g++)
            {
                int point = gagne(g, a[i]);
                tab[i][j][g] = tab[i - 1][j][g] + tab[i][j - 1][g] - tab[i - 1][j - 1][g] + point;
            }

            if (i==N){
                
            }

        }
    }

    


    return 0;
}

int gagne(int j1, int j2) // todo check
{
    // p=0 h=1 s=2

    if (j1 == H && j2 == S)
        return 1;
    if (j1 == S && j2 == P)
        return 1;
    if (j1 == P && j2 == H)
        return 1;
    return 0;
}
