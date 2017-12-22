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
const int maxn = 61;
// s, w, n, e
vector<ii> dirs{{1,0}, {0,-1}, {-1,0}, {0,1}};

int mat[maxn][maxn] = {{0}};
int n;
int curDirIdx;
bool valid(int i, int j){
	return (i>= 0 && j >= 0 && i < n && j < n && mat[i][j] == 0);
}

int gain(ii p1, ii p2){
	if(p1 == p2) return 1;
	else if(p1.fi * p2.fi + p1.se * p2.se == 0) return 2;
	return 3;
}

void walk(ii pos, int coloca){
	mat[pos.fi][pos.se] = coloca++;
	int best = 4;
	ii nxt = mp(-1,-1);
	for(const ii& dir : dirs){
		if(valid(pos.fi + dir.fi, pos.se + dir.se)){
			if( gain(dirs[curDirIdx], dir) < best){
				nxt = mp(pos.fi+dir.fi, pos.se+dir.se);
				best = gain(dirs[curDirIdx], dir);
			}
		}
	}
	if(best == 4) return;
	walk(nxt, coloca);
}

int main(){
	cin >> n;
	char c;
	cin >> c;
	if(c == 's') curDirIdx = 0;
	if(c == 'w') curDirIdx = 1;
	if(c == 'n') curDirIdx = 2;
	if(c == 'e') curDirIdx = 3;
	int x, y;
	scanf("%d %d", &x, &y);
	walk(mp(x,y), 1);
	rp(i, n){
		rp(j, n){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

