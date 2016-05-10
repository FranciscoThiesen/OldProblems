#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    int d, tax;
    scanf("%d %d", &d, &tax);
    int arr[100010];
    for(int i = 0; i < d; ++i)
        scanf("%d", &arr[i]);
    vector<int> profit(d+1);
    profit[0] = 0;
    profit[1] = max(0, arr[1] - arr[0] - tax);
    cout << "profit " << profit[1] << " do " << 1 << endl;
    for(int j = 2; j < d+1; ++j)
    {
        if(profit[j-1] == profit[j-2])
            profit[j] = max(arr[j] - arr[j-2] - tax,max( profit[j-1] + (arr[j] - arr[j-1] - tax), profit[j-1] + (arr[j] - arr[j-1]))) ;
        else
            profit[j] = max(arr[j] - arr[j-2] - tax,max( profit[j-1] + (arr[j] - arr[j-1] - tax), profit[j-1] + (arr[j] - arr[j-1]))) ;            
        cout << "profit " << profit[j] << " do " << j << endl;
    }
    int ans = 0;
    int curHigh = 0;
    for(int k = 0; k < d+1; ++k)
    {
        if(profit[k] >= 0)
        {
            if(profit[k] > curHigh)
            {
                curHigh = profit[k];
            }
        }
        else
        {
            ans += curHigh;
            curHigh = 0;
        }
    }
    cout << ans << endl;
    return 0;

}
