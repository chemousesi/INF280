#include<cstdio>
#include<string>
#include <string.h>

using namespace std;


int main(){
    char s[1005];
    scanf("%[^\n]s", s);
    int price, quantity;
    int tot = 0;
    while(strcmp(s, "TOTAL"))
    {
        scanf("%d %d\n", &price, &quantity);
        tot += price * quantity;
        scanf("%[^\n]s", s);
    }
    int restaurant_tot;
    scanf("%d",&restaurant_tot );
    

    if(restaurant_tot>tot)
        printf("PROTEST\n");
    else
        printf("PAY\n");

}