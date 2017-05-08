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
	int n, k;
	cin >> n >> k;
	vector<int> pos(n);
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		pos[i] = x;
	}
	sort(pos.begin(), pos.end());
	int ans = 0;
	int lastPos = 0;
	int lowPos = pos[0];
	int antenaPos;
	//colocando a primeira antena o mais longe possivel

	for(int i = 0; i < pos.size(); ++i)
	{
		if(pos[i] > lowPos + k)
		{
			int prev = lowPos;
			antenaPos = pos[i-1];
			ans++;
			for(int j = i; j < pos.size(); ++j)
			{
				if(pos[j] > antenaPos + k)
				{
					lowPos = pos[j];
					break;
				}
			}
			if(lowPos == prev)
				break;
		}	
	}
	if(antenaPos + k < pos[n-1])
			ans++;
	ans = max(1, ans);
	cout << ans << endl;
	return 0;
}