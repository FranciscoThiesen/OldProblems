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

int main()
{
	string s;
	cin >> s;
	char ant = s[0];
	F(i,1,s.size())
	{
		if(s[i] == ant)
		{
			cout << "Impossible" << endl;
			return 0;
		}
		ant = s[i];
	}
	vector<int> freq(26, 0);
	char rep;
	F(i,0,s.size())
	{
		freq[s[i] - 'A']++;
		if(freq[s[i] - 'A'] == 2)
			rep = s[i];
	}
	cout << "jabirola" << endl;	
	int mat[13][2];
	int init = -1;
	int end = -1;
	F(i,0,s.size())
	{
		if(s[i] == rep)
		{
			if(init == -1)
				init = i;
			else
			{
				end = i;
				break;
			}
		}
	}
	cout << "jabirola" << endl;
	int entreRep = end-1 - init+1 + 1;
	if(entreRep%2 == 1)
	{
		mat[12-(entreRep/2)][0];
	}
	cout << "jabirola" << endl;
	int repX = 12-(entreRep/2);
	string meio;
	F(i,init+1, end)
		meio += s[i];
	string meio1;
	string meio2;
	for(int i = 0; i < meio.size(); ++i)
	{
		if(i < meio.size()/2)
			meio1 += meio[i];
		else
			meio2 += meio[i];
	}
	cout << "jabirola" << endl;
	if(meio2.size() > meio1.size())
	{
		for(int x = repX; x < 13; ++x)
		{
			mat[x][1] = meio2[x-repX];
		}
		for(int x2 = repX + 1; x2 < 13; ++x2)
		{
			mat[x2][0] = meio1[x2-(repX+1)];
		}
	}
	cout << "jabirola" << endl;
	else
	{
		for(int x = repX + 1; x < 13; ++x)
		{
			mat[x][1] = meio2[x-(repX+ 1)];
		}
		for(int x2 = repX + 1; x2 < 13; ++x2)
		{
			mat[x2][0] = meio1[x2-(repX+1)];
		}

	}
	cout << "jabirola" << endl;
	string a1;
	string a2;
	F(i,0,s.size())
	{
		if(s[i] != rep)
			a1 += rep;
		else
			break;
	}
	cout << "jabirola" << endl;
	F(i, end+1, s.size())
	{
		a2+=s[i];	
	}
	cout << "jabirola" << endl;
	if(a1.size() >= a2.size())
	{
		int cabeEmY0 = repX - 0;
		if(a1.size() < cabeEmY0)
		{
			F(i,cabeEmY0 - a1.size(),repX)
			{
				mat[i][0] = a1[i - (cabeEmY0 - a1.size())];
			}
			reverse(a2.begin(), a2.end());
			F(j,0,cabeEmY0 - a1.size())
				mat[j][0] = a2[j];
			F(k, cabeEmY0 - a1.size(), a2.size() - cabeEmY0 - a1.size())
			{
				mat[k][1] = a2[k];
			}	
		}
		else if(a1.size() == cabeEmY0)
		{
			F(i,0,repX)
				mat[i][0] = a1[i];
			F(j,0,a2.size())
				mat[j][1] = a2[j];
		}
		else
		{
			string pqp;
			string pqp2;
			F(i,cabeEmY0-a1.size(), a1.size())
				pqp += a1[i];
			F(i, 0, pqp.size())
				mat[i][0] = pqp[i]; 	
			F(i,0,cabeEmY0-a1.size())
				pqp2 += a1[i];
			reverse(pqp2.begin(), pqp2.end());
			F(i,0,pqp2.size())
				mat[i][1] = pqp2[i];
			F(i,pqp2.size(), pqp2.size() + a2.size())
			{
				mat[i][1] = a2[pqp2.size() - 1];
			}
			
		}	
	}
	else
	{
		string f = a1;
		a1 = a2;
		a2 = f;
		reverse(a1.begin(), a1.end());
		reverse(a2.begin(), a2.end());
		int cabeEmY0 = repX - 0;
		if(a1.size() < cabeEmY0)
		{
			F(i,cabeEmY0 - a1.size(),repX)
			{
				mat[i][0] = a1[i - (cabeEmY0 - a1.size())];
			}
			reverse(a2.begin(), a2.end());
			F(j,0,cabeEmY0 - a1.size())
				mat[j][0] = a2[j];
			F(k, cabeEmY0 - a1.size(), a2.size() - cabeEmY0 - a1.size())
			{
				mat[k][1] = a2[k];
			}	
		}
		else if(a1.size() == cabeEmY0)
		{
			F(i,0,repX)
				mat[i][0] = a1[i];
			F(j,0,a2.size())
				mat[j][1] = a2[j];
		}
		else
		{
			string pqp;
			string pqp2;
			F(i,cabeEmY0-a1.size(), a1.size())
				pqp += a1[i];
			F(i, 0, pqp.size())
				mat[i][0] = pqp[i]; 	
			F(i,0,cabeEmY0-a1.size())
				pqp2 += a1[i];
			reverse(pqp2.begin(), pqp2.end());
			F(i,0,pqp2.size())
				mat[i][1] = pqp2[i];
			F(i,pqp2.size(), pqp2.size() + a2.size())
			{
				mat[i][1] = a2[pqp2.size() - 1];
			}
			
		}	
	}
	F(y, 0, 2)
	{
		F(x,0,13)
		{
			cout << mat[x][y];
		}
		cout << endl;
	}
	return 0;
}