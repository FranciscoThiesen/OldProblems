#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> nums;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		nums.push_back(x);
	}
	int ans = 1;
	int fst = nums[0];
	int cur = 1;
	for(int i = 1; i < nums.size(); ++i)
	{
		if(nums[i] > fst)
			fst = nums[i], cur++;
		else
			cur = 1, fst = nums[i];
		ans = max(ans, cur);

	}
	cout << ans << endl;
}
