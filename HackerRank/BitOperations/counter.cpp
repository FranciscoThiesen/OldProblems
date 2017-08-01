/*input
5
6703734870638684097
7597026128958891522
13174607262084689114
6959712971461184279
12572864054437627553
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
int main()
{


	int t;
	cin >> t;
	while(t--)
	{
		
		ull x;
		cin >> x;
		int turn = 0, r;
		while(x != 1)
		{
			//cout << x << endl;
			if((x & (x-1)) == 0)
				x >>= 1;
			else{
				ll power = (ll)log2(x);
				x -= (ll)pow(2,power);
			}
			turn++;
		}
		if(turn%2 ^ 1) cout << "Richard" << endl;
		else cout << "Louise" << endl;
	}
	
	return 0;
}