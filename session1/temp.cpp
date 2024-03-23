#include <cstdio>
#include <cstdlib>
using namespace std;


int main(){
    
    // use scan f to read lines or strings 
  
    char str[20];
    int min = 50;
    int max = -50;
    while(scanf("%s", str) != EOF){
       
        int temp = atoi(str);
        if (temp > 50 || temp < -50)
        {
            continue;
        }
        if(temp < min){
            min = temp;
        }
        if(temp > max){
            max = temp;
        }
    }
    printf("%d %d\n", min, max);

    return 0;
}