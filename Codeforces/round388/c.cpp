/*input
9
RRDDRDDDR
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>

using namespace std;

#define gcd __gcd
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define IOS ios::sync_with_stdio(0);

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int main()
{
	IOS
	cin.tie();
	int n;
	cin >> n;
	string s;
	cin >> s;
	int d = 0;
	int r = 0;
	vector<short> pos(n, 0);
	vector<int> posR;
	vector<int> posD;
	for(int i = 0; i<n; ++i)
	{
		if(s[i] == 'D')
		{
			d++;
			pos[i] = 1;
			posD.pb(i);
		}
		else
		{
			r++;
			pos[i] = 2;
			posR.pb(i);
		}
	}
	if(d == 0)
	{
		cout << "R" << endl;
		return 0;
	}
	if(r == 0)
	{
		cout << "D" << endl;
		return 0;
	}
	while(d > 0 && r > 0)
	{
		for(int i = 0; i < n; ++i)
		{
			if(pos[i] == 1)//eligible for vote
			{
				auto it = upper_bound(posR.begin(), posR.end(), i);
				int idx = (it - posR.begin());
				if(it == posR.end())
				{
					pos[posR[0]] = -1;
					posR.erase(posR.begin());
				}
				else
				{
					pos[posR[idx]] = -1;
					posR.erase(it);
				}
				r--;
				if(!r)
					break;
				
			}
			if(pos[i] == 2)//eligible for vote
			{
				auto it = upper_bound(posD.begin(), posD.end(), i);
				int idx = (it - posD.begin());
				if(it == posD.end())
				{
					pos[posD[0]] = -1;
					posD.erase(posD.begin());
				}
				else
				{
					pos[posD[idx]] = -1;
					posD.erase(it);
				}				
				d--;
				if(d == 0)
					break;
			}
		}
	}
	if(r == 0)
		cout << "D" << endl;
	else
		cout << "R" << endl;
	return 0;
}