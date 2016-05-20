#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iomanip>
#include <utility>
using namespace std;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    vector<unsigned long long int> nums;
    for(int i = 0; i < n; ++i)
    {
        unsigned long long a;
        cin >> a;
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    for(int i = 0; i < n-1; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            if(nums[j] - nums[i] == k)
                ans++;
            if(nums[j]-nums[i] > k)
                break;
        }
    }
    cout << ans << endl;
    return 0;

}
