#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        int size;
        cin >> size;
        unsigned long long int sumL = 0;
        unsigned long long int sumR = 0;
        int arr[size];
        for(int j = 0; j < size; ++j)
        {
            scanf("%d", &arr[j]);
            sumR += arr[j];
        }
        int mod = 0;
        for(int k = 0; k < size; ++k)
        {
            sumR -= arr[k];
            if(sumR == sumL)
            {
                cout << "YES" << endl;
                mod++;
                break;
            }
            else
                sumL += arr[k];
        }
        if(!mod)
            cout << "NO" << endl;
    }
    return 0;
}
