#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <utility>
#include <unordered_set>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		unordered_multiset<int> freq;
		int n;
		scanf("%d", &n);
		set<int> val;
		unsigned long long ans = 0;
		for(int i = 0; i < n; ++i)
		{
			int x;
			scanf("%d", &x);
			freq.insert(x);
			val.insert(x);
		}
		for(auto& p : val)
		{
			ans += freq.count(p) * (freq.count(p) - 1);
		}
		cout << ans << endl;
	}
	return 0;
}