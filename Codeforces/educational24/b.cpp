/*input
3 3
2 2 3
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

int main()
{
	int n, m;
	cin >> n >> m;// n = jogadores, m = rodadas
	vi vec(m); // lideres em cada rodada
	rp(i, m)cin >> vec[i];
	//unordered_set<int> stepSize;
	vi ans(n, 0); // resposta, numero dos n jogadores
	int prev = vec[0]; // prev = primeiro lider
	int cur, step;
	vector<int> used(n+1, -1);
	used[0] = true;
	fr(i, 1, m)
	{

		cur = vec[i]; // proximo = vec[1]
		if(prev >= cur) // se o anterior eh maior que o atual, entao eu dei uma volta 
			step = (n-prev)+cur;
		else
			step = cur-prev;// se nao eu andei direto
		//printf("prev = %d, cur = %d, step = %d\n", prev, cur, step);

		if((used[step] != -1 && used[step] != prev-1) || (ans[prev-1] != 0 && ans[prev-1] != step)) // se o step ja foi usado, retorna -1
		{
			//printf("i = %d, prev = %d, step = %d\n", i, prev, step);
			cout << -1 << endl;
			return 0;
		}
		ans[prev-1] = step; // resposta na posicao prev = quanto eu andei
		used[step] = prev-1; // step agora foi usado
		//printf("ans[%d] = %d\n", prev-1, step);
		prev = cur; // anterior = vec[1] ... e assim por diante
	}
	vector<int> tantoFaz; // vetor para os elementos que nao foram preenchidos
	fr(i, 1, n+1)
		if(used[i] == -1) // se used[i] == false, entao algum elemento tem que ter o valor i no vetor
			tantoFaz.pb(i); // tanto faz.pb(i)
	int idx = 0;
	for(int i = 0; i < n; ++i)
	{
		if(ans[i] == 0)
			ans[i] = tantoFaz[idx++];
	}
	if(idx != tantoFaz.size())
	{	
		cout << -1 << endl;
		return 0;
	}
	else
	{
		for(auto& p : ans)
			cout << p << " ";
		cout << endl;
	}
	return 0;
}
