// https://www.codechef.com/APRIL17/problems/DISHLIFE
#include <bits/stdc++.h>
 
using namespace std;
 
#define fr(i,a,b)for(int (i) = (a); (i) < (b); ++(i))
#define fu(i, n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
 
 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t, n, k, x, p;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		vector<int> freq(k, 0);
		vector<vector<int> > isla(n);
		fu(i, n)
		{
			cin >> x;
			fu(j, x)
			{
				cin >> p;
				isla[i].pb(p-1);
				freq[p-1]++;
			}
		}
		bool sad = false; bool some = false;
		fu(i, k)
		{
			if(freq[i] == 0)
			{
				sad = true;
				break;
			}
		}
		if(sad)cout << "sad" << endl;
		else
		{
			fu(i, n)
			{
				bool need = false;
				fu(j, isla[i].size())
				{
					if(freq[isla[i][j]] == 1)
					{
						need = true;
						break;
					}
				}
				if(!need)
				{
					some = true;
					break;
				}
			}
			if(some)cout << "some" << endl;
			else cout << "all" << endl;
		}
	}
	return 0;
} 