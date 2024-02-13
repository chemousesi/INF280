# include <iostream>
# include <cmath>

using namespace std;


int main(){

    float s, h, v;
    cin >> s >> h >> v;
    int n;
    cin >> n ;

    float a[n][2];
    // lenght of the ith cube a[i][0] and a[i][1] is is the density   
    for (int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }

    float sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        /* code */

        if (a[i][1] > 1){
            sum += a[i][0]*a[i][0]*a[i][0];
        }
        else{
            sum += a[i][0]*a[i][0]*a[i][0]*a[i][1];
        } 

        float vol = sum;
        float water_final_vol = vol+v;
        cout << water_final_vol/s << endl;

    }
    




    return 0;
}