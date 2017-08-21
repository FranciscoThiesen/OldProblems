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
	int n;
	scanf("%d", &n);
	vector<int> pos;
	vector<int> neg;
	rp(i, n){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == 1)pos.pb(y);
		else neg.pb(y);
	}
	sort(all(pos));
	sort(all(neg));
	int q;
	scanf("%d", &q);
	rp(i, q){
		int s;
		scanf("%d", &s);
		int idx = upper_bound(all(pos), s) - pos.begin();
		int idx2 = (upper_bound(all(neg), -s)- neg.begin());
		//cout << idx << " " << idx2 << endl;
		printf("%d\n", idx + idx2);
	}
	return 0;
}

