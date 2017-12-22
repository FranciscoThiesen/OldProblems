/*input
7
16 37 50 35 12 39 24
*/
#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int maxn = 1e5 + 5;

int n, x;
vi vet;


// 0 = Left, 1 = dir, 2 = init
vi generateSeq(){
	vi s;
	s.pb(n/2);
	int l = n/2 - 1;
	int r = n/2 + 1;
	while(l >= 0 || r <= n-1){
		if(l >= 0) s.pb(l);
		if(r <= n-1) s.pb(r);
		l--; r++;
	}
	return s;
}

int main(){
	
	scanf("%d", &n);
	vi d(n);
	vet.assign(n, 0);
	rp(i, n) scanf("%d", &vet[i]);

	sort(vet.rbegin(), vet.rend());
	vi p = generateSeq();
	rp(i, n) d[p[i]] = vet[i];

	double resp = 0.0;
	double senu = sin(2*M_PI / n);
	
	rp(i, n) resp += (d[i] * d[(i+1)%n] * senu)/2.0;
	printf("%.3lf\n", resp);
	return 0;
}

