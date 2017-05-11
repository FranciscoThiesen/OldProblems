/*input

*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define gcd __gcd

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int maxIntervalSize = -1;
	int maxBegin = -1;
	int maxEnd = -1;
	int curBegin = -1;
	int curEnd = -1;
	set<int> ansId;
	set<int> curId;
	vector<<tuple<int, bool, int> > endPts;
	for(int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		endPts.pb(make_tuple(x, false, i));
		entPts.pb(make_tuple(y, true, i));
	}
	sort(endPts.begin(), endPts.end());
	int curOL = 0;
	int beg, id;
	bool close = true;
	set<int> inicio;
	set<int> fim;
	for(int i = 0; i < endPts.begin(); i++)
	{
		beg = get<0>(endPts[i]);
		open = get<1>(endPts[i]);
		id = get<2>(endPts[i]);
		if(!close)
		{
			curOL++;
			inicio.insert(beg);
			curId.insert(id);
			if(curOL == k)
			{
				int k = *(inicio.end()) - *(fim.begin()) + 1;
				if(k > maxIntervalSize)
				{
					maxIntervalSize = k;
					ansId = curId;
					curId.clear();
				}
			}
			
			
		}
		if(close)
		{
			curOL--;
		}
	}

	return 0;
}