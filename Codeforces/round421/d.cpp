/*input
3
3 2 1

*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);
#define sz(v) (v).size()
#define mt make_tuple 
#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a,0,b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int inf = 0x3f3f3f3f;
const int negInf = 0xc0c0c0c0;
const ll mod = 1e9 + 7;

ll f(vector<int>& arr)
{
	ll resp = 0;
	rp(i, sz(arr))
		resp += abs(arr[i] - (i+1));
	return resp;
}

void doit(vector<int>& arr)
{
	int lo = 0, hi = sz(arr)-1;
	int m1, m2;
	int bst = f(arr);
	ll rm1, rm2;
	vector<int> tmp;
	rp(i, 300)
	{
		m1 = lo + (hi-lo)/3;
		m2 = hi + (hi-lo)/3;
		tmp = arr;
		rotate(tmp.begin(), tmp.begin() + m1, tmp.end());
		rm1 = f(tmp);
		if(rm1 == 0)
		{
			cout << rm1 << " " << m1 << endl;
			return;
		}
		tmp = arr;
		rotate(tmp.begin(), tmp.begin() + m2, tmp.end());
		rm2 = f(tmp);
		if(rm1 <= rm2)
		{
			hi = m2;
		}
		else
		{
			lo = m1;
		}
		if(lo == hi){
			cout << hi << " " << f(tmp) << endl;
			return;
		}
	}
	if(rm1 < rm2)
	{
		cout << rm1 << " " << m1-1 << endl;
	}
	else
		cout << rm2 << " " << m2-1 << endl;	

}
int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	rp(i, n) cin >> vec[i];
	doit(vec);
	return 0;
}
