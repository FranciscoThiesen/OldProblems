/*input
5 1
AABBB
*/

#include <bits/stdc++.h>

using namespace std;

#define gcd                         __gcd

#define fr(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define fu(i,n) fr(i,0,n)

#define sc(a) scanf("%d", &a) 
#define sc2(a,b) scanf("%d%d", &a, &b)
#define sc3(a,b,c) scanf("%d%d%d", &a, &b, &c)

#define pr(a) printf("%d\n", a)
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)

#define clr(a,x) memset(a,x,sizeof(a))
#define char2Int(c) (c-'0')
#define sz(x) ((int)((x).size()))

#define remax(a,b) (a)=max((a),(b))
#define remin(a,b) (a)=min((a),(b));

#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(), (c).rend()

#define IOS ios_base::sync_with_stdio(0)
#define INF 1001001001

#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back

typedef vector<int> vi; 
typedef pair<int,int> ii; 
typedef long long ll;
typedef unsigned long long ull;

main(){
	int n, k;
	cin >> n >> k;
	vector<int> fst(26, -1);
	vector<int> lst(26, -1);
	string s;
	cin >> s;
	for(int i = 0; i < (int)s.size(); ++i){
		int t = s[i] - 'A';
		if(fst[t] == -1)
			fst[t] = i;
		lst[t] = i;
	}
	int open = 0;
	bool ok = true;
	for(int i = 0; i < (int)s.size(); ++i){
		int x = s[i] - 'A';
		if(fst[x] == i) open++;
		if(open > k) ok = false;
		if(lst[x] == i) open--;

	}
	if(!ok) cout << "YES" << endl;
	else cout << "NO" << endl;
}