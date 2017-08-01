#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;
#define gcd                         __gcd
#define OR |
#define AND &
#define XOR ^
#define bit(x,i) (x&(1<<i))  //select the bit of position i of x
#define lowbit(x) ((x)&((x)^((x)-1))) //get the lowest bit of x
#define hBit(msb,n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define max(a,b) (a<b?b:a)
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

int main()
{
    int y = 1;
    int x = 1;
    int counter = 0;
    while( x + y != 0)
    {
        getII(y,x);
        if(x+y == 0)
            break;
        counter++;
        int arr[x][y];
        int aux[x][y];
        int aux2[x][y];
        for(int i = 0; i < y; ++i)
        {
            for(int j = 0; j < x; ++j)
            {
                scanf("%d", &arr[j][i]);
                aux[j][i] = 0;
                aux2[j][i] = 0;
            }
        }
        int difX = 1;
        int difY = 1;
        int dx = 0;
        int dy = 0;
        while(difX != 0 || difY != 0)
        {
            cin >> difX >> difY;
            dx += difX;
            dy += difY;
        }
        //moving in x
        cout << dx << endl;
        if(dx >= 0)
        {
            int moverX = dx%x;
            F(a,0,y)
            {
                F(b,0,x)
                {
                    if(b + moverX < x)
                        aux[b+moverX][a] = arr[b][a];
                    else
                    {
                        cout << "potato" << endl;
                        aux[b-((b+moverX)%x)][a] = arr[b][a];
                    }
                }
            }
        }
        else if(dx < 0)
        {
            int moverX = dx%-x;
            cout << moverX << endl;
            F(f,0,y)
            {
                F(g,0,x)
                {
                    if(g + moverX >= 0)
                        aux[g+moverX][f] = arr[g][f];
                    else
                        aux[x+moverX+g][f] = arr[g][f];
                }
            }
        }
        if(dy >= 0)
        {
            int moverY = dy%y;
            F(q,0,y)
            {
                F(w,0,x)
                {
                    if(q + moverY < y)
                        aux2[w][q+moverY] = aux[w][q];
                    else
                        aux2[w][q-(q+moverY-y+q)] = aux[w][q];
                }
            }
        }
        else if(dy < 0)
        {
            int moverY = dy%-y;
            F(t,0,y)
            {
                F(h,0,x)
                {
                    if(t + moverY >= 0)
                        aux2[h][t+moverY] = aux[h][t];
                    else
                        aux2[h][y+moverY+t] = aux[h][t];
                }
            }
        }
        cout << "Teste " << counter << endl;
        F(v,0,y)
        {
            F(c,0,x)
            {
                cout << aux[c][v] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
