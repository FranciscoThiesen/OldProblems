#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        int fi = arr[0];
        bool pos = false;
        int cursize = 1;
        for(int j = 1; j < n; ++j)
        {
            if(arr[j] == fi)
                cursize++;
            else
            {
                fi = arr[j];
                cursize = 1;
            }
            if(cursize == 3)
            {
                pos = true;
                break;
            }
        }
        if(pos)
            cout << "Yes"<< endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
