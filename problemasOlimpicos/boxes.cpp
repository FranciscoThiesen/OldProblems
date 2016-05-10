#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <string>
using namespace std;
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max(a,b) (a<b?b:a)
#define abs(x) (x<0?(-x):x) // big bug here if "-x" is not surrounded by "()"
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
// directions
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int fxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){F(i,0,SZ(t))s<<t[i]<<" ";return s; }

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

vvi AdjList(100);
int visitado[100];
void dfs(int u)
{
    if (visitado[u]) {
        return;
    }
    visitado[u] = 1;
    for(int j = 0; j < (int)AdjList[u].size(); j++)
    {
        int v = AdjList[u][j];
        if(visitado[v] == 0)
            dfs(v);
    }
}

bool conexo(int x, int v) {
    // limpa todas as marcas de visitação
    for (int i=1; i <= v; i++) visitado[i] = 0;
    
    // inicia busca no nó de índice 0
    dfs(x);
    
    // testa se todos os nós foram visitados com uma única busca
    for (int i= 1; i <= v; i++)
        if (!visitado[i])
            return false;
    return true;
}

void conexaum(bool x)
{
    if( x == 0)
        cout << "falha";
    else
        cout << "normal";
}

vvi boxes(1010);
int main()
{

    while(true)
    {
        int moves = 0;
        int pile;
        int a,b;
        int tam;
        getII(a,b);
        if(a == 0 && b == 0)
            return 0;
        F(i,0,b)
        {
            int x;
            getI(x);
            F(j,0,x)
            {
                int k;
                getI(k);
                boxes[i].pb(k);
                if(k == 1)
                {
                    moves = x - j - 1;
                    pile = i;
                    tam = x;
                
                }
                    
                }
            }
            if(pile == 0)
                    {
                        moves += max(0,(int)tam - boxes[pile+1].size());
                        cout << max(moves,0) << endl;
                        return 0;
                    }
                    if(pile == b-1)
                    {
                        moves += max(0,(int)tam - boxes[pile-1].size());
                        cout << max(moves,0) << endl;
                        return 0;

        }

        moves += max(0,tam - min(boxes[pile-1].size(), boxes[pile+1].size()));
        cout << max(0,moves) << endl;
    }
    return 0;
}