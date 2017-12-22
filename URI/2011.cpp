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
typedef tuple<int, int, int> iii;
constexpr int inf = 0x3f3f3f3f;
constexpr int neginf = 0xc0c0c0c0;
constexpr int maxn = 1001;

int n, m, a, b, c, d;

vector<iii> adjList[maxn];

double t;

double cost(int a, int b){return a*t + b;}

double dijkstra(){
	multiset<pair<double, int> > q;
	q.insert(mp(0, 0));
	vector<double> dist(n, 1e11);
	dist[0] = 0;
	while(!q.empty()){
		pair<double, int> x = *(q.begin());
		q.erase(q.begin());
		for(const iii& v : adjList[x.se]){
			double nD = x.fi;
			nD += cost(get<1>(v), get<2>(v));
			if(dist[get<0>(v)] > nD){
				if(dist[get<0>(v)] != 1e11){
					q.erase(mp(dist[get<0>(v)], get<0>(v)));
				}
				dist[get<0>(v)] = nD;
				q.insert(mp(dist[get<0>(v)], get<0>(v)));
			}
		}
	}
	return dist[n-1];
}

int main(){
	scanf("%d %d", &n, &m);
	rp(i, m){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		--a;--b;
		adjList[a].pb(mt(b,c,d));
		adjList[b].pb(mt(a,c,d));
	}
	double lo = 0, hi = 1440.0;
	double fm1, fm2, m1, m2;
	rp(i, 110){
		m1 = (2 * lo + hi)/3.0;
		m2 = (2*hi + lo)/3.0;
		t = m1;
		fm1 = dijkstra();
		t = m2;
		fm2 = dijkstra();
		if(fm1 > fm2) hi = m2;
		else lo = m1;
	}
	printf("%.5lf\n", fm1);
	return 0;
}

