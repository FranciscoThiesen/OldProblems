#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>  
#include <iostream>  
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main()
{
	int caixas, clientes;
	getII(caixas, clientes);
	priority_queue<ii, vii, greater<ii> > caixasDisponiveis;
	F(i,0,caixas)
		caixasDisponiveis.push(mp(0,i));
	vii filaClientes;
	int ans = 0;
	F(i,0,clientes)
	{
		int a, b;
		getII(a,b);
		filaClientes.pb(mp(a,b));
		ii cx = caixasDisponiveis.top();
		caixasDisponiveis.pop();
		if(cx.first - a > 20)
			ans++;
		caixasDisponiveis.push(mp(max(a,cx.first)+b, cx.second));
	}
	cout << ans << endl;
	return 0;
}
