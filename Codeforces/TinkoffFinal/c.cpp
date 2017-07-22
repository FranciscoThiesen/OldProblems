/*input
tinkoff
zscoder
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
#define sz(a) (a).size()
#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a,0,b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)
#define IOS ios::sync_with_stdio(0);

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;

//looks greedy with a twist
int main()
{
	string a, b;
	cin >> a >> b;
	
	sort(all(a));
	sort(all(b));
	
	string resp;
	rp(i, sz(a))resp+='?';

	int initA = 0, initB = 1 + (sz(a)-1)/2;
	int endA = (sz(a)-1)/2, endB = sz(a)-1;
	

	int begResp = 0, endResp = sz(a)-1;

	rp(i, sz(a))
	{
		if(!(i%2))
		{
			if(a[initA] >= b[endB])
			{
				resp[endResp] = a[endA];
				endA--;
				endResp--;
			}
			else
			{
				resp[begResp] = a[initA];
				begResp++;
				initA++;
			} 
		}
		else
		{
			if(a[initA] >= b[endB])
			{
				resp[endResp] = b[initB];
				initB++;
				endResp--;
			}
			else
			{
				resp[begResp] = b[endB];
				begResp++;
				endB--;
			}
		}
	}

	cout << resp << endl;

	return 0;
}
