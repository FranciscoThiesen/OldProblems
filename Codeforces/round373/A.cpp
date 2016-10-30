#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		nums.push_back(x);
	}
	if(nums[n-1] == 15)
	{
		cout << "DOWN" << endl;
		return 0;
	}
	else if(nums[n-1] == 0)
	{
		cout << "UP" << endl;
		return 0;
	}
	else if(n == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	else
	{
		if(nums[n-2] > nums[n-1])
			cout << "DOWN" << endl;
		else
			cout << "UP" << endl;
	}
	return 0;

}