#include <cstdio>
#include <cstdlib>
#include <cstring>
char *get_first_n_letters(int n);

const char *ALL_LETTERS = "abcdefghijklmnopqrstuvwxyz";

int main()
{
    int n;
    scanf("%d", &n);

    char flechette[2 * n - 1][2 * n - 1];

    char *s = get_first_n_letters(n);

    // create square table flechette of n-1 x n-1 where in the center of the tabke is the last letter and all around is the rest of the string
    // the table should be symetric
    const int len = 2 * n - 1;
    int len_s = strlen(s);
    for (int k = 0; k < len_s; k++)
    {
        for (int i = k; i < len - k; i++)
        {
            for (int j = k; j < len - k; j++)
            {
                flechette[i][j] = s[k];
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            printf("%c", flechette[i][j]);
        }
        printf("\n");
    }

    return 0;
}

char *get_first_n_letters(int n)
{
    char *res = (char *)malloc(n + 1);
    return strncpy(res, ALL_LETTERS, n);
}