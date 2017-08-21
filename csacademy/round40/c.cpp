/*input
4
0101
3 4 3 4
1 1 1 1
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

int lsb(int i){ return i & -i;}

struct BIT{
	int size;
	vi table;
	BIT(int sz){
		table.resize(sz+1, 0);
		size = sz+1;
	}
	// update position pos by delta
	// pos is zero indexed
	void update(int pos, int delta){
		++pos;
		while(pos <= size){
			table[pos] += delta;
			pos += lsb(pos);
		}
	}

	// update the interval [l, r] by delta
	// l and r should be 0-indexed
	void rangeUpdate(int l, int r, int delta){
		update(l, delta);
		update(r+1, -delta);
	}
	//the i parameter is 0 indexed
	int pointQuery(int i){
		++i;
		int sum = 0;
		while(i > 0){
			sum += table[i];
			i -= lsb(i);
		}
		return sum;
	}
};

int main(){
	int n;
	cin >> n;
	BIT b(n);
	string s;
	cin >> s;
	vector<bool> on(n, false);
	rp(i, n){
		if(s[i]-'0' == 1)on[i] = true;
	}
	vi R(n), C(n);
	rp(i, n){ cin >> R[i]; R[i]--;}
	rp(i, n) cin >> C[i];
	ll resp = 0;
	for(int i = 0; i < n; ++i){
		bool ok = on[i];
		int qry = b.pointQuery(i);
		if(qry%2) ok = !ok;
		if(ok){
			resp += C[i];
			b.rangeUpdate(i, R[i], 1);
		}
	}
	cout << resp << endl;
	return 0;
}

