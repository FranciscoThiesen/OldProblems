#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <iostream>
#include <utility>
#include <functional>
#include <cstring>
#include <cstring>
#include <string>
#include <istream>
#include <sstream>
#define MAXN 1500
#define INF 1000000000
#define OR |
#define AND &
#define XOR ^
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define IN(i,l,r) (l<i&&i<r) //the next for are for checking bound
#define LINR(i,l,r) (l<=i&&i<=r)
#define LIN(i,l,r) (l<=i&&i<r)
#define INR(i,l,r) (l<i&&i<=r)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n)) //handy if the input is right after the definition of a variable
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m))
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k))
#define TESTS wez(testow)while(testow--) //for multilple cases problems
#define whileZ int T; getI(T); while(T--) // the same as above
#define getS(x) scanf("%s", x) //get a char* string
#define clr(a,x) memset(a,x,sizeof(a)) //set elements of array to some value
#define char2Int(c) (c-'0')
#define lastEle(vec) vec[vec.size()-1] 
#define SZ(x) ((int)((x).size()))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define REMIN(a,b) (a)=min((a),(b));
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end()) 
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end()) 
#define ll long long //data types used often, but you don't want to type them time by time
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); //to synchronize the input of cin and scanf
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n",n); }
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
//for vectors
#define pb push_back

using namespace std;

typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 


vector<vector<int> > graph(MAXN);
int capacity[MAXN][MAXN] = {{0}};


long long maxFlow(int source, int sink)
{
    int residualCapacity[MAXN][MAXN] = {{0}};
    while(true)
    {
        int prev[MAXN];
        memset(prev, -1, sizeof(prev));
        int atual[MAXN] = {0};
        prev[source] = source;
        atual[source] = INF;
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < graph[u].size(); ++i)
            {
                int v = graph[u][i];
                if(capacity[u][v] - residualCapacity[u][v] > 0 && prev[v] == -1)
                {
                    prev[v] = u;
                    atual[v] = min(atual[u], capacity[u][v] - residualCapacity[u][v]);
                    if(v != sink)
                        q.push(v);
                    else
                    {
                        while(prev[v] != v)
                        {
                            u = prev[v];
                            residualCapacity[u][v] += atual[sink];
                            //residualCapacity[v][u] -= atual[sink];
                            v = u;
                        }
                        goto end;
                    }
                }    
            }
        }
        end:;
        if(prev[sink] == -1)
        {
            long long sum = 0;
            for(int i = 0; i < MAXN; ++i)
            {
                sum+= residualCapacity[source][i];
            }

            return sum;
        }
    }
}

int main()
{
    int n, m;
    getII(n,m);
    vector<string> frases;
    vector<pair<char, int> > conditions;
    string fodase;
    getline(cin, fodase);
    F(i,0,n)
    {
        string x;
        getline(cin, x);
        frases.pb(x);
        graph[0].pb(i+1);
        capacity[0][i+1] = 1;
    }
    F(j,0,m)
    {
        char k;
        int y;
        cin >> k >> y;
        conditions.pb(mp(k,y));
        graph[n+j+1].pb(n+m+1);
        capacity[n+j+1][n+m+1] = 1;
    }
    // OBS: cada frase eh um vertice, que so tera uma aresta para um amigo se essa frase satisfizer a condicao necessária
    // a numeracao de vertices comecara do 1, pois o 0 eh o supervertice, que é ligado a todas as frases
    F(i,0,n)
    {
        int freq[26] = {0};
        F(j,0,frases[i].size())
        {
            if(frases[i][j] >= 'A' && frases[i][j] <= 'Z' && frases[i][j] != ' ')
            {
                freq[frases[i][j] - 'A']++;
            }
            else if(frases[i][j] >= 'a' && frases[i][j] <= 'z' && frases[i][j] != ' ')
            {
                freq[frases[i][j] - 'a']++;
            }
        }
        F(j,0,m)
        {
            if(freq[conditions[j].fi - 'A'] >= conditions[j].se)
            {
                graph[i+1].push_back(n+j+1);
                capacity[i+1][n+j+1] = 1;
            }
        }
    }
    cout << "thor vai ganhar ouro na obi" << endl;
    cout << maxFlow(0, n+m+1)  << endl;
    return 0;
}

