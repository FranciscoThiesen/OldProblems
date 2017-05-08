/*input
4
1
2
3
4
*/
#include <vector>
#include <algorithm>
#include <cstdio>
#include <utility>
#include <iostream>
#include <unordered_set>
#include <set>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

#define pb push_back

int calcDiv(long long n)
{
	int ans = 0;
	for(int i = 1; i <= ceil(sqrt(n)); ++i)
	{
		if(n%i == 0)
		{
			ans++;
			if(n/i != i)
				ans++;
		}
	}
	return ans;
}

vector<int> numDivs;
unordered_map<int, long long> achieved;

void solve()
{
	int maxAchieved = 1;
	achieved[1] = 1;
	numDivs.pb(1);
	long long beg = 1;
	for(int i = 1; maxAchieved < 1000; ++i)
	{
		beg += i;
		int div = calcDiv(beg);
		cout << "number of divisors = " << div << " current number = " << beg << endl;
		if(div > maxAchieved)
		{
			numDivs.pb(div);
			achieved[div] = beg;
			maxAchieved = div;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	solve();
	while(t--)
	{
		int n;
		cin >> n;
		int idx = lower_bound(numDivs.begin(), numDivs.end(), n) - numDivs.begin();
		cout << achieved[numDivs[idx]] << endl;
	}
	return 0;
}