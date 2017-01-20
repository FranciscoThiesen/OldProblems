#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> nums(4);
	for(int i = 0; i < 4; ++i)
	{
		int k;
		cin >> k;
		nums[i] = k;
	}
	sort(nums.begin(), nums.end());
	cout <<(int) abs( ((nums[3] + nums[0]) - (nums[1] + nums[2]))) << endl;
	return 0;
}
