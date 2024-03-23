# include <iostream>
# include <cmath>
# include <iomanip>

using namespace std;


int main(){

    float s, h, v;
    cin >> s >> h >> v;
    int n;
    cin >> n ;

    float a[n][3];
    // lenght of the ith cube a[i][0] and a[i][1] is is the density and the max height of the ith cube   
    for (int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }

    float sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        int vol_cub_i = a[i][0]*a[i][0]*a[i][0]*a[i][1];
        if ((a[i][1] < 1) && (a[i][1] > 0)){
            sum += a[i][0]*a[i][0]*a[i][0];
            
        }
        else{// >= 1  il coule ne entier
            sum += a[i][0]*a[i][0]*a[i][0]*a[i][1];
        } 


        // 


        float vol = sum;
        float water_final_vol = vol+v;
        cout << water_final_vol/s << endl;

    }
    




    return 0;
}
