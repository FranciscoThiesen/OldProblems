/*input
3 2 4 4
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

int dist[9][9];

vector<ii> dirs{{1,1}, {1,-1}, {-1, 1}, {-1,-1}};
bool sameDiag(int r1, int c1, int r2, int c2){
	if(r1 + c1 == r2 + c2) return true;
	if(abs(r1 - c1) == abs(r2 - c2)) return true;
	return false;
}
bool samePos(int r1, int c1, int r2, int c2){
	return (r1 == r2 && c1 == c2);
}
bool valid(int i, int j){
	return ( i > 0 && j > 0 && j <= 8 && i <= 8);
}

void dfs(int r1, int c1){
	queue<ii> fila;
	dist[r1][c1] = 0;
	fila.push(mp(r1, c1));
	while(!fila.empty()){
		ii topo = fila.front();
		fila.pop();
		int rt = topo.fi;
		int ct = topo.se;
		rp(i, 8){
			rt++; ct++;
			if(!valid(rt, ct))break;
			if(dist[rt][ct] == -1){
				dist[rt][ct] = dist[topo.fi][topo.se] + 1;
				fila.push(mp(rt, ct));
			}
		}
		rt = topo.fi;
		ct = topo.se;
		rp(i, 8){
			rt++; ct--;
			if(!valid(rt, ct))break;
			if(dist[rt][ct] == -1){
				dist[rt][ct] = dist[topo.fi][topo.se] + 1;
				fila.push(mp(rt, ct));
			}
		}
		rt = topo.fi;
		ct = topo.se;
		rp(i, 8){
			rt--; ct++;
			if(!valid(rt, ct))break;
			if(dist[rt][ct] == -1){
				dist[rt][ct] = dist[topo.fi][topo.se] + 1;
				fila.push(mp(rt, ct));
			}
		}
		rt = topo.fi;
		ct = topo.se;
		rp(i, 8){
			rt--; ct--;
			if(!valid(rt, ct))break;
			if(dist[rt][ct] == -1){
				dist[rt][ct] = dist[topo.fi][topo.se] + 1;
				fila.push(mp(rt, ct));
			}
		}
	}
}

int main(){
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	memset(dist, -1, sizeof dist);
	dfs(r1, c1);
	cout << dist[r2][c2] << endl;
	return 0;
}

