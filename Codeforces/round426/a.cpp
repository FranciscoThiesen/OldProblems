/*input
^ v
6
*/

#include <bits/stdc++.h>

using namespace std;

#define gcd                         __gcd

#define fr(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)

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

int idx(char c){
	if(c == '^') return 0;
	if(c == '>') return 1;
	if(c == 'v') return 2;
	if(c == '<') return 3;
}


int idx2(char c){
	if(c == '^') return 0;
	if(c == '<') return 1;
	if(c == 'v') return 2;
	if(c == '>') return 3;
}
main(){
	char st, end;
	cin >> st >> end;
	int s = idx(st);
	int e = idx(end);
	int s2 = idx2(st);
	int e2 = idx2(end);
	int n;
	cin >> n;
	if(s == e){
		puts("undefined");
	}
	else{
		bool cw = false;
		if( (s+n)%4 == e){
			cw = true;
		}
		bool ccw = false;
		if( (s2 + n)%4 == e2) ccw = true;
		if(ccw && cw){
			puts("undefined");
		}
		else if(cw) puts("cw");
		else puts("ccw");
	}
}