// https://www.codechef.com/MARCH17/problems/XENTASK

#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define mp make_pair
#define fi first
#define fr(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define fu(i, a) fr(i,0,a)
 
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vi a(n), b(n);
		fu(i,n)cin>>a[i];
		fu(i,n)cin>>b[i];
		int r1 = 0;
		int r2 = 0;
		fu(i,n)
		{
			if(i%2 == 0)
			{
				r1 += a[i];
				r2 += b[i];
			}
			else
			{
				r1 += b[i];
				r2 += a[i];
			}
		}
		cout << min(r1, r2) << endl;
	}
	return 0;
} 