#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second

vector<pair<int, int> > prod;
pair<int, int> maria;

int main()
{
	int n;
	cin >> n;

	int a, b;
	cin >> a >> b;
	maria.fi = a;
	maria.se = b;

	int maxResp = 1;
	int minResp = 1;

	for(int i = 0; i < n - 1; i++)
	{
		pair<int, int> temp;
		cin >> a >> b;
		temp.fi = a;
		temp.se = b;

		prod.pb(temp);

	}

	for(int i = 0; i < n - 1; i++)
	{
		if(prod[i].fi > maria.fi && prod[i].se > maria.se)
		{
			maxResp++;
			minResp++;
		}
		else if((prod[i].fi > maria.fi && prod[i].se < maria.se)
				|| (prod[i].fi < maria.fi && prod[i].se > maria.se)
				|| (prod[i].fi == maria.fi && prod[i].se == maria.se))
		{
			minResp++;
		}
	}

	cout << maxResp << " " << minResp << endl;


	return 0;
}