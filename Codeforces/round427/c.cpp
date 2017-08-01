/*input
3 4 5
1 1 2
2 3 0
3 3 1
0 1 1 100 100
1 2 2 4 4
2 2 1 4 7
1 50 50 51 51
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
typedef vector<vi> vvi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;

int lsb(int i){ return i & -i;}
struct BIT2D{
	int size;
	vvi table;
	int N, M;
	BIT2D(int n, int m){
		table.resize(n+1, vector<int>(m+1, 0)); // 0-indexed
		N = n+1;
		M = m+1;
	}
	
	int query(int i, int j){ // 0-indexed, returns sum of the rectangle defined by (0,0) (i, j)
		++i;++j;
		int sum = 0, tmpJ = j;
		while(i > 0){
			j = tmpJ;
			while(j > 0){
				sum += table[i][j];
				j -= lsb(j);
			}
			i -= lsb(i);
		}
		return sum;
	}

	void update(int i, int j, int delta){ // 0-indexed
		++i;++j;
		int tmpJ = j;
		while(i < N){
			j = tmpJ;
			while(j < M){
				table[i][j] += delta;
				j += lsb(j);
			}
			i += lsb(i);
		}
	}
};


int main(){
	int n, q, c, x, y, z, x1, y1, x2, y2, K, start;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> c;
	BIT2D temp(101, 101);
	vector<BIT2D> t(11, temp); 

	rp(i, n){
		cin >> x >> y >> z;
		rp(i, 11){
			if(z > c)z = 1;
			else{
				t[i].update(x, y, z);
				z++;
			}
		}
	}
	rp(i, q){
		cin >> K >> x1 >> y1 >> x2 >> y2;
		K %= (c+1);
		int resp = 0;
		resp += t[K].query(x2, y2);
		resp -= t[K].query(x2, y1-1);
		resp -= t[K].query(x1-1, y2);
		resp += t[K].query(x1-1, y1-1);
		cout << resp << endl;
	}
	return 0;
}