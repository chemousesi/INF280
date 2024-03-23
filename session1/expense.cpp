#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
    long double sum = 0;
    long double x;
    while (scanf("%Lf", &x) != EOF){
        sum += x;
    }

    printf("%.2Lf\n", sum);


}
