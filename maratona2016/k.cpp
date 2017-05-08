#include <bits/stdc++.h>

using namespace std;


#define endl '\n'
#define pb push_back
#define mp make_pair
#define ull unsigned long long

int main()
{
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> freq(n, 0);
	vector<pair<int, int> > kill;
	for(int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		kill.pb(mp(a-1,b-1));
		freq[a-1]++;
		freq[b-1]++;
	}
	int ans = 0;
	//brute-force
	for(int i = 0; i < n; ++i)
	{
	 	// i pode ser o lobo?
		vector<int> cpy = freq;
		int y;
		int z;
		for(int g = 0; g < kill.size(); ++g)
		{
			if(g == i)
			{
				y = kill[g].first;
				z = kill[g].second;
				continue;
			}
			if(kill[g].first == i)
				cpy[kill[g].second]--;
			else if(kill[g].second == i)
				cpy[kill[g].first]--;
		}
		int f = freq[i];
		int flag = 0;
		if(cpy[y] > cpy[z])
			cpy[y]++;
		else
			cpy[z]++;
		for(int j = 0; j < cpy.size(); ++j)
		{
			if( cpy[j] >= f && j != i)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
	
}