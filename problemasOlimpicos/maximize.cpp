#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> nums(3);
	for(int i = 0; i < 3; i++)
	{
		scanf("%d", &nums[i]);
	}
	sort(nums.begin(),nums.end());
	int total = 0;
	int x = 0;
	if(nums[x] == 1)
	{
		nums[x] = 0;
		nums[x+1] = nums[x+1] + 1;
		x++;
	}
	else
	{
		total += nums[x] * nums[x+1];
		x++;
	}
	printf("%d", total);
	return 0;
}
