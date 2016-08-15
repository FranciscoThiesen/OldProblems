#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int t = 1;
    while(t != 0)
    {
        scanf("%d", &t);
        if(t == 0)
            return 0;
	vector<int> nums;
	for(int i = 0; i < t; ++i)
	{
		int x;
		cin >> x;
		nums.push_back(x);
	}
	int cur = nums[0];
	int mx = nums[0];
	for(int i = 1; i < nums.size(); ++i)
	{
		if(cur < 0)
			cur = nums[i];
		else
			cur += nums[i];
		mx = max(cur, mx);
	}
	if(mx > 0)
		printf("The maximum winning streak is %d.\n", mx);
	else
		printf("Losing streak.\n");
        
    }
	return 0;
}
