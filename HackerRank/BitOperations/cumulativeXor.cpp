/*input
3
2 4
2 8
5 9
*/
#include <bits/stdc++.h>

using namespace std;

#define popcnt(x) __builtin_popcount(x)
#define LSOne(x) ((x) & (-(x)))

#define bit(x,i) (x&(1<<i))

#define fi first
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define se second

typedef unsigned long long ull;
typedef long long ll;

ll x(ll l)
{
	if(l%4 == 0) return l;
	if(l%4 == 1) return 1;
	if(l%4 == 2) return l+1;
	return 0;
}

int main()
{	
	int t;
	int start = 0;
	int cXor[21] = {0};
	int ccXor[21] = {0};
	for(int i = 1; i <= 20; ++i)
		cXor[i] = cXor[i-1] ^ i;
	for(int i = 1; i <= 20; ++i)
		ccXor[i] = ccXor[i-1] ^ cXor[i];

	for(int i = 1; i <= 20; ++i)
	{
		cout << "ccXor " << i << " = " << ccXor[i] << endl;
	}
	cin >> t;
	while(t--)
	{
		ll l, r, xl, xr;
		cin >> l >> r;
		xr = x(r);
		xl = x(l-1);
		cout << "xr = " << xr << " xl = " << xl << endl;
		cout << (x(r) ^ x(l-1)) << endl;

	}
	
	return 0;
}