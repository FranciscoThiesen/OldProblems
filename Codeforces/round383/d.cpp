#include <bits/stdc++.h>
using namespace std;
#define gcd                         __gcd
#define OR |
#define AND &
#define XOR ^
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define whileZ int T; getI(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define clr(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1] 
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
#define INF 1001001001
#define PI 3.1415926535897932384626
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n",n); }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define MAXN 10000
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

vector<bool> visited(1001, false);

int CalcMaxValue(const std::vector<std::vector<int>>& weight,
                 const std::vector<std::vector<int>>& value,
                 int max_weight) {
    std::vector<int> last(max_weight + 1, -1);
    if (weight.empty()) return 0;
    for (int i = 0; i < weight[0].size(); ++i) {
        if (weight[0][i] > max_weight) continue;
        last[weight[0][i]] = std::max(last[weight[0][i]], value[0][i]);
    }
    std::vector<int> current(max_weight + 1);
    for (int i = 1; i < weight.size(); ++i) {
        std::fill(current.begin(), current.end(), -1);
        for (int j = 0; j < weight[i].size(); ++j) {
            for (int k = weight[i][j]; k <= max_weight; ++k) {
                if (last[k - weight[i][j]] < 0) continue;
                current[k] = std::max(current[k], last[k - weight[i][j]] + value[i][j]);
            }
        }
        std::swap(current, last);
    }    
    return *std::max_element(last.begin(), last.end());
}

vector<int> scc(int root, vector<vector<int> >& adjList)
{
	int orig = root;
	int totBt = 0;
	visited[root] = true;
	vector<int> scc;
	scc.pb(root);
	queue<int> q;
	q.push(root);
	while(q.empty())
	{
		int u = q.front();
		q.pop();
		F(j,0,adjList[u].size())
		{
			int v = adjList[u][j];
			if(visited[v] == false)
			{
				visited[v] = true;
				q.push(v);
				scc.pb(v);
			}
		}
	}
	return scc;
}


int main()
{
	int n, m, w, x;
	getIII(n,m,w);
	vvi adjList(n);
	vector<int> we(n);
	vector<int> bt(n);
	F(i,0,n)
	{
		getI(x);
		we[i] = x;
	}
	F(i,0,n)
	{
		getI(x);
		bt[i] = x;
	}
	F(i,0,m)
	{
		int a, b;
		getII(a,b);
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	vector<vector<int> > sccs;
	for(int i = 0; i < n; ++i)
	{
		if(!visited[i])
		{
			sccs.pb(scc(i, adjList));
		}
	}
	vector<vector<int> > wei;
	vector<vector<int> > vals;
	for(int i = 0; i < sccs.size(); ++i)
	{
		vector<int> b;
		vector<int> pes;
		int tb = 0;
		int tw = 0;
		for(int j = 0; j < sccs[i].size(); ++j)
		{
			tb += b[sccs[i][j]];
			b.pb(bt[sccs[i][j]]);
			tw += we[sccs[i][j]];
			pes.pb(we[sccs[i][j]]);
			
		}
		pes.pb(tw);
		b.pb(tb);
		wei.pb(pes);
		vals.pb(b);		
	}
	cout << CalcMaxValue(wei, vals, w) << endl;
	return 0;
}
