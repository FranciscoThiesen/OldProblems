/*input
3
10 10
1 2 1 1
5 5 6 5
6 4 5 4
2 1 2 0
*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define uniq(v) (v).erase(unique(all(v)), v.end())
#define IOS ios::sync_with_stdio(0);
#define sz(v) (v).size()

#define fr(a, b, c) for(int (a) = (b); (a) < (c); ++(a))
#define rp(a, b) fr(a,0,b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pr(a) printf("%d\n", a);
#define pr2(a, b) printf("%d %d\n", a, b)
#define pr3(a, b, c) printf("%d %d %d\n", a, b, c)

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int Inf = 0x3F3F3F3F;
const int negInf = 0xC0C0C0C0;
const ll mod = 1e9 + 7;

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

const int maxn = 1e5 + 5;
int main()
{
	int k;
	sc(k);
	int n, m;
	int a, b, c, d;
	int x1, y1, x2, y2, lft, rht, tp, btm, r1,r2,r3,r4;
	sc2(n, m);
	segtree<int> right(maxn);
	segtree<int> left(maxn);
	segtree<int> top(maxn);
	segtree<int> down(maxn);
	vector<tuple<int, int, int, int> > sofas(k);
	rp(i, k)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		sofas[i] = make_tuple(a,b,c,d);
		lft = max(a, c); // para checar quantos estao a esquerda
		rht = min(a, c); // para checar quantos estao a direita
		btm = max(b, d); // para checar quantos estao abaixo
		tp = min(b, d); // para checar quantos estao acima
		printf("Inseri o sofa em (%d, %d)   (%d, %d)\n", a,b,c,d);
		top.update(tp,1);
		down.update(btm,1);
		left.update(lft, 1);
		right.update(rht, 1);
	}
	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("Estamos procurando resultados (%d, %d, %d, %d)\n", a,b,c,d);
	rp(i, k)
	{
		tie(x1, y1, x2, y2) = sofas[i];
		lft = max(x1, x2); // para checar quantos estao a esquerda
		rht = min(x1, x2); // para checar quantos estao a direita
		btm = min(y1, y2); // para checar quantos estao abaixo
		tp = max(y1, y2); // para checar quantos estao acima
		
		printf("Quantos caras tem no intervalo horizontal[0, %d]\n", lft-1);
		printf("Quantos caras tem no intervalo horizontal[%d, maxn]\n", rht+1);
		r1 = left.query(0, lft-1);
		r2 = right.query(rht+1, maxn);
	
		printf("Quantos caras tem no intervalo vertical[0, %d]\n", tp-1);
		printf("Quantos caras tem no intervalo vertical[%d, maxn]\n", btm+1);
		r3 = top.query(0, tp-1);
		r4 = down.query(btm+1, maxn);

		printf("Encontramos (%d, %d, %d, %d)\n", r1,r2,r3,r4);
		puts("\n\n");

		if(r1 == a && r2 == b
		 && r3 == c	&& r4 == d)
		{
			pr(i+1);
			return 0;
		}
	}
	pr(-1);


	return 0;
}
