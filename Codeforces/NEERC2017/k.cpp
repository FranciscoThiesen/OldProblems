/*input

*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int (i) = (a); (i) < (n); ++(i))
#define per(i,a,n) for(int (i) = (n-1); (i) >= (a); --(i))
#define fi first
#define se second
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define SZ(a) ((int)(a.size()))
#define init() ios::sync_with_stdio(0);in.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int mod = 1000000007;

ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }
int main(){
	ifstream in("kotlin.in", ios::in);
	ofstream out("kotlin.out", ios::out);
	int h, w, n;
	in >> h >> w >> n;
	if(n > h * w){
		out << "Impossible" << endl;
		return 0;
	}
	if(n == 1){
		if(h == 1 && w == 1){
			out << "." << endl;
			return 0;
		}
		rep(i, 0, h){
			rep(j,0,w){
				if(i == 0 || j == 0 && h > 1 && w > 1) out << "#";
				else out << '.';
			}
			out << endl;
		}
		return 0;
	}
	int mat[h][w];
	memset(mat, 0, sizeof mat);
	int regions = n;
	int posW = w/2;
	int posH = h/2;
	int a1 = -1, a2 = -1;
	rep(s1, 1, posW+2){
		if(regions%s1) continue;
		int mul = regions/s1;
		if(mul <= posH+1){
			a1 = s1;
			a2 = mul;
			break;
		}
	}
	if(a1 + a2 < 0){
		out << "Impossible" << endl;
		return 0;
	}
	vi paintLin(h,0), paintCol(w,0);
	rep(i, 0, a1-1) paintCol[1+2*i] = 1;
	rep(i, 0, a2-1) paintLin[1+2*i] = 1;
	rep(i,0,h){
		rep(j, 0, w){
			if(paintCol[j] || paintLin[i]){
				out << "#";
			}
			else out << ".";
		}
		out << endl;
	}
	return 0;
}

