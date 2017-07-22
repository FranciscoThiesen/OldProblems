/*input
5
10 20 30 20 10
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
bool unimodal(vector<int>& vec)
{
	int startInc = inf;
	int stConst = inf;
	int startDec = inf;
	int prev = -1;
	prev = vec[0];
	for(int i = 1; i < vec.size(); ++i)
	{
		if(vec[i] > prev)
		{
			if(startDec != inf || stConst != inf) return false;
			startInc = min(startInc, i);
		}
		else if(vec[i] < prev)
		{
			startDec = min(startDec, i);
		}
		else
		{
			if(startDec != inf) return false;
			stConst = min(stConst, i);
		}
		prev = vec[i];
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	vi v(n);
	for(int i = 0; i < n; ++i) cin >> v[i];
	if(n == 1) cout << "YES" << endl;
	else{
		if(unimodal(v)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}