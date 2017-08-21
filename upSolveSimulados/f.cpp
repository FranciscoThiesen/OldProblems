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

int main(){
	deque<pair<int, int> > bs;
	queue<int> gente;
	int n,m,k,t;
	scanf("%d %d %d %d", &n, &m, &k, &t);
	vi g;
	vi g2;
	rp(i, n){
		int x;
		scanf("%d", &x);
		g.pb(x);
	}
	sort(all(g));
	rp(i, n) gente.push(g[i]);
	rp(i, m){
		int coord;
		scanf("%d", &coord);
		g2.pb(coord);
	}
	sort(all(g2));
	rp(i, m) bs.push_back(mp(k, g2[i]));
	int rsp = 0;
	while(!gente.empty()){

		int inicio = gente.front();// primeira pessoa da fila
		if(bs.empty()) break; // se nao tem bunker break
		ii bunker = bs.front(); // primeiro bunker
		if(abs(inicio - bunker.se) <= t){ // se posso botar a pessoa no bunker
			gente.pop();
			int cap = bunker.fi - 1;
			bs.pop_front();
			rsp++;
			if(cap > 0){
				bs.push_front(mp(cap, bunker.se));
			}
		}
		else{
			if(inicio < bunker.se){
				gente.pop();
			}
			else
			{
				bs.pop_front();
			}
		}
	}
	printf("%d\n", rsp);
	return 0;
}

