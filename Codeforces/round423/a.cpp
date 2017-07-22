/*input
4 1 1
1 1 2 1
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define gcd __gcd
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;

int main()
{
	int n, o, t;
	int remainingTwo = 0;
	int rem2 = 0;
	cin >> n >> o >> t;
	int resp = 0;
	int resp2 = 0;
	int o2 = o;
	int t2 = t;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		if(x == 1)
		{
			if(remainingTwo > 0)
				remainingTwo--;
			else{
				if(o > 0) o--;
				else if(t > 0){
					t--;
					remainingTwo++;
				}
				else resp++;
			}
		}
		else{
			if(t > 0) t--;
			else resp+=2;
		}

		if(x == 1)
		{
			if(rem2 > 0) rem2--;
			else if(t2 > 0){
				t2--;
				rem2++;
			}
			else if(o2 > 0)o2--;
			else resp2++;
		}
		else{
			if(t2 > 0) t2--;
			else resp2+=2;
		}
	}
	cout << min(resp, resp2) << endl;
}