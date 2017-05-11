#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);

#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a, 0 b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)
#define IOS ios::sync_with_stdio(0);

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;

#define LC 2*node+1
#define RC 2*node+2
#define REC int node = 0, int L = 0, int R = -1

template <typename T>
struct segtree {
    T op(const T& a, const T& b) {
        // This is THE function you want to change.
        return a+b;
    }
    int N;
    vector<T> tree;
    segtree(int _N) : N(_N) {
        int e = 32 - __builtin_clz(N-1);
        if (N == 1) e = 0;
        N = 1<<e;
        tree.resize(1<<(e+1));
    }
    // Vector to be in the leaves
    void setup(vector<T>& V, REC) {
        if (R == -1) R = N;
        if (L >= sz(V)) return;
        if (R - L == 1) {
            tree[node] = V[L];
            return;
        }
        int m = (L + R)/2;
        setup(V, LC, L, m);
        setup(V, RC, m, R);
        tree[node] = op(tree[LC], tree[RC]);
    }
    // Does "V[i] = nv"
    T update(int i, const T& nv, REC) {
        if (R == -1) R = N;
        if (i < L || i >= R) return tree[node];
        if (R - L == 1) return tree[node] = nv;
        int m = (L + R)/2;
        return tree[node] = op(	update(i, nv, LC, L, m),
    				update(i, nv, RC, m, R));
    }
    // queries the CLOSED interval [i,j]
    T query(int i, int j) {
        return _query(i, j+1);
    }
    T _query(int i, int j, REC) {
        if (R == -1) R = N;
        if (i <= L && R <= j) return tree[node];
        int m = (L + R)/2;
        if (i >= m) return _query(i, j, RC, m, R);
        else if (j <= m) return _query(i, j, LC, L, m);
        return op(_query(i, j, LC, L, m), _query(i, j, RC, m, R));
    }
};
#undef LC
#undef RC
#undef REC

const int inc = 5 * 10000 + 1;

int main()
{
	int sz, id = 0, k, op;
	unordered_map<int, int> numToId;
	unordered_map<int, int> idToNum;
	sc(sz);
	segtree<int> arv(sz + inc);
	rp(i, sz)
	{
		sc(k);
		idToNum[id] = k;
		numToId[k] = id;
		arv.update(id, 1);
		id++;
	}
	sc(op);
	rp(j, op)
	{
		char c; int x, y;
		scanf("%c", &c);
		if(c == 'Q')
		{
			sc2(x,y);
			cout << arv.query(x+1, y-1) << endl;
		}
		else if(c == 'I')
		{
			sc2(x, y);
		}
		else
		{
			sc(x);
			arv.update(numToId[x], 0);
		}
	}

	return 0;
}
