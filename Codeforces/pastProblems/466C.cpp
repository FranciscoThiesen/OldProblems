#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}	
	vector<long long> sm(n);
	sm[0] = nums[0];
	for(int i = 1; i < n; ++i)
	{
		sm[i] = sm[i-1]+nums[i];
	}
	vector<int> l1;
	vector<int> l2;
	for(int i = 0; i < n; ++i)
	{
		if(3*sm[i] == sm[n-1] && i >= 0 && i <= n-3)
			l1.push_back(i);
		if(3*sm[i] == 2*sm[n-1] && i >= 0 && i <= n-2)
			l2.push_back(i);	
	}
	//two pointers
	long long ans = 0;
	if(l1.size() == 0 && l2.size() == 0)
	{
		cout << "0\n";
		return 0;
	}
	int j = 0;
	for(int i = 0; i < l1.size(); ++i)
	{
		while(l2[j] <= l1[i])
			j++;
		ans += l2.size() - j;
	}
	cout << ans << "\n";
	return 0;
	
}