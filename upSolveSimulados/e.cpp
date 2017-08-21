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

const int maxn = 501;

vector<ii> dirs{{-1,0}, {1,0}, {0,1}, {0,-1}};


char mat[2][maxn][maxn];

int n, m;

bool valid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}

int menorCaminho(int idx){
	queue<ii> q;
	int dist[n][m];
	memset(dist, -1, sizeof dist);
	dist[0][0] = 0;
	q.push(mp(0,0));
	while(!q.empty()){
		ii topo = q.front();
		q.pop();
		rp(i, 4){
			int x = topo.fi + dirs[i].fi;
			int y = topo.se + dirs[i].se;
			if(valid(x,y) && dist[x][y] == -1){
				if(mat[idx][x][y] == '.'){
					dist[x][y] = dist[topo.fi][topo.se] + 1;
					q.push(mp(x,y));
				}
			}
		}
	}
	return dist[n-1][m-1];
}

int menorCaminhoConjunto(){
	queue<ii> q;
	int dist[n][m];
	memset(dist, -1, sizeof dist);
	dist[0][0] = 0;
	q.push(mp(0,0));
	while(!q.empty()){
		ii topo = q.front();
		q.pop();
		rp(i, 4){
			int x = topo.fi + dirs[i].fi;
			int y = topo.se + dirs[i].se;
			if(valid(x,y) && dist[x][y] == -1){
				if(mat[0][x][y] == '.' && mat[1][x][y] == '.'){
					dist[x][y] = dist[topo.fi][topo.se] + 1;
					q.push(mp(x,y));
				}
			}
		}
	}
	return dist[n-1][m-1];
}

int main(){
	cin >> n >> m;
	rp(i, n){
		rp(j, m){
			cin >> mat[0][i][j];
		}
	}
	string nda;
	getline(cin, nda);
	rp(i, n){
		rp(j, m){
			cin >> mat[1][i][j];
		}
	}
	int c1 = menorCaminho(0);
	int c2 = menorCaminho(1);
	if(c1 != c2){
		cout << "NO" << endl;
		return 0;
	}
	else if(c1 == -1){
		cout << "NO" << endl;
	}
	else{
		int c3 = menorCaminhoConjunto();
		if(c1 == c3){
			cout << "YES" << endl;
		}	
		else cout << "NO" << endl;
	}
	return 0;
}

