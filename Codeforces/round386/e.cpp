/*input
5 4 0
1 2
3 1
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_set<int> used;
	int needOdd = 0;
	int needEven = 0;
	int totOdd = 0;
	int totEven = 0;
	vector<int> eug(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> eug[i];
		if(used.find(eug[i]) != used.end())
		{
			if(eug[i]%2)
				needOdd++;
			else
				needEven++;
		}
		if(eug[i]%2)
			totOdd++;
		else
			totEven++;
	}

}