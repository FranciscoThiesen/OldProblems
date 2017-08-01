/*input
5 5
5 4 3 2 1
1 5 3
1 3 1
2 4 3
4 4 4
2 5 3
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

const int maxn = 10010;

int arr[maxn];
int main()
{
	int n, m, a, b, c, maior, menor, nMen, nMai, elem;
	sc2(n, m);
	rp(i, n)sc(arr[i]);
	rp(i, m)
	{
		sc3(a, b, c);
		--a; --b; --c;
		nMen = c-a;
		nMai = b-c;
		maior = 0;
		menor = 0;
		elem = arr[c];
		fr(i, a, b+1)
		{
			if(arr[i] > elem)
				maior++;
			if(arr[i] < elem)
				menor++;
		}
		if(menor == nMen && maior == nMai) puts("Yes");
		else puts("No");

	}
	return 0;
}
