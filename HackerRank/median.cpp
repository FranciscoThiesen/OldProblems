#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> nums;
    for(int i = 0; i < n; ++i)
    {
        int a;
        scanf("%d", &a);
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());
    cout << nums[floor(n/2.0)] << endl;
    return 0;
}
