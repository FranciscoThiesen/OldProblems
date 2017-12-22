/*input
5 1
1 1 1 1 1
2 5 1
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
#define init() ios::sync_with_stdio(0);cin.tie(0);
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;
const int mod = 1000000007;
constexpr int tam = 22;
ll powmod(ll a, ll b){ ll res = 1; a %= mod; assert(b>=0); for(;b;b>>=1){ if(b&1) res = (res*a)%mod; a = (a*a)%mod;} return res; }


struct node{
	bool leaf;
	int count;
	node(bool l = false, int c = 0) : leaf(l), count(c) {}
};

int N, Q, a, b, c;
constexpr int blockSize = 101;
constexpr int maxn = 1e5 + 5;
map<int, node*> tries[blockSize + 1];
int arr[maxn];
int accu[maxn];

vi toBin(int x){
	vi s;
	for(int i = 21; i >= 0; --i){
		int dig = (x & (1 << i)) > 0 ? 1 : 0;
		s.pb(dig);
	}
	return s;
}

int trie_search(map<int, node*>& trie, vi& s){
	int pos = 1;
	for(const int& v : s){
		pos *= 2;
		if(v) pos++;
		if(trie[pos] == NULL) return 0;
	}
	return (trie[pos]->leaf) ? trie[pos]->count : 0;
}

void trie_insert(map<int, node*>& trie, vi& s){
	int pos = 1;
	rep(i,0,tam){
		pos *= 2;
		if(s[i]) pos += 1;
		if(trie[pos] == NULL){
			trie[pos] = new node(false, 0);
		}
	}
	trie[pos]->leaf = true;
	trie[pos]->count += 1;
}

void trie_modify(map<int, node*>& trie, vi& s){
	int start = 2, end = 3;
	rep(lvl, 0, tam){
		if(s[lvl]){
			for(int elem = start; elem <= end; ++elem){
				node* tmp = NULL;
				if(trie[elem] != NULL){
					tmp = trie[elem];	
				}
				trie[elem] = trie[elem^1];
				trie[elem^1] = tmp;
				elem++;
			}	
		}
		start *= 2;
		end = 2*end + 1;
	}
}

int main(){
	int stBlock, ndBlock, ans, borda;
	scanf("%d %d", &N, &Q);
	vi tmp;
	rep(i, 0, N)
	{
		scanf("%d", &arr[i]);
		if(!i) accu[i] = arr[i];
		else accu[i] = accu[i-1] ^ arr[i];
		tmp = toBin(accu[i]);
		trie_insert(tries[i/blockSize], tmp);
	}
	rep(i,0,Q){
		scanf("%d %d %d", &a, &b, &c);
		if(a == 2){
			stBlock = 0;
			--b;
			ndBlock = b/blockSize;
			ans = 0;
			tmp = toBin(c);
			rep(j, stBlock, ndBlock){
				ans += trie_search(tries[j], tmp);
			}
			borda = ndBlock * blockSize;
			rep(j, borda, b+1){
				if(accu[j] == c) ans++;
			}	
			printf("%d\n", ans);
		}
		else{ // treta
			--b;
			int modifica = arr[b] ^ c;

		}
	}
	return 0;
}
