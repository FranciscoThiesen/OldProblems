// https://www.codechef.com/MARCH17/problems/EXTRAN
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
		int vec[n];
		fu(i, n)cin >> vec[i];
		sort(vec, vec + n);
		int ans = 0;
		fr(i, 1, n)
		{
			if(vec[i] == vec[i-1])
			{
				ans = vec[i];
				break;
			}
		}
		if(ans)
		{
			cout << ans << endl;
			continue;
		}
		if(vec[n-1] - vec[n-2] > 1)
			ans = vec[n-1];
		else
			ans = vec[0];
		cout << ans << endl;
	}
	return 0;
} 