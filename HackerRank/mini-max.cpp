#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define MAXN 50001
#define fi first
#define se second

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<unsigned long long> nums;
	unsigned long long tot = 0;
	for(int i = 0; i < 5; ++i)
	{
		unsigned long long k;
		cin >> k;
		nums.pb(k);
		tot+= k;
	}
	sort(nums.begin(), nums.end());
	cout << tot - nums[0] << " " << tot - nums[4] << endl;
	return 0;
}