#include <iostream>
#include <cstdio>
using namespace std;


int main(){

    int w, n;

    scanf("%d", &w);
    scanf("%d", &n);

    int sum= 0;
    int wi, li;

    for (int i = 0; i < n; i++){    
        scanf("%d %d", &wi, &li);
        sum += wi*li;
    }

    printf("%d\n", sum/w);
    
    
    return 0;
}