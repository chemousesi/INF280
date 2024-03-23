#include <cstdio>

using namespace std;
int solve(double *arr, int n, float diffmax);
double calculate_diff_max(double *arr, int n);

int main()
{

    int n;
    double diffmax;
    scanf("%d\n%lf\n", &n, &diffmax);
    double arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lf\n", &arr[i]);
    }

    printf("%d\n", solve(arr, n, diffmax));
}

int solve(double *arr, int n, float diffmax)
{

    int count = 0;
    double max_temp_diff;
    max_temp_diff = calculate_diff_max(arr, n);
    // calcaulte the max difference between the elements of the array
    double smootharr[n]{0};
    smootharr[0] = arr[0];
    smootharr[n - 1] = arr[n - 1];

    while (max_temp_diff >= diffmax)
    {

        for (int i = 1; i < n - 1; i++)
        {
            smootharr[i] = (arr[i - 1] + arr[i + 1]) / 2;
        }

        max_temp_diff = calculate_diff_max(smootharr, n);

        for (int i = 0; i < n; i++)
        {
            arr[i] = smootharr[i];
        }

        count++;
    }

    return count;
}

double calculate_diff_max(double *arr, int n)
{
    double max_diff = -100000;
    for (int i = 1; i < n; i++)
    {
        double temp_diff = arr[i] - arr[i - 1];
        if (temp_diff > max_diff)
        {
            max_diff = temp_diff;
        }
    }
    return max_diff;
}