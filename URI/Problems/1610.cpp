#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <bitset>
using namespace std;
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define getI(a) scanf("%d", &a) //next three are handy ways to get ints, it's also force you to use '&' sign
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
//for map, pair
#define mp make_pair
#define fi first
#define se second
// for debug
#define MAXN 10010
//for vectors
#define pb push_back
typedef int elem_t;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 

vvi AdjList(MAXN);
bitset<MAXN> visited;
bitset<MAXN> toVisit;
bitset<MAXN> visiting;
bool cycleFind(int v)
{
	if(visited[v] == false)
	{
		visiting[v] = true;
		F(i,0,AdjList[v].size())
		{
			if(visited[AdjList[v][i]] == true)
				continue;
			else if(visiting[AdjList[v][i]] == true || cycleFind(AdjList[v][i]))
			{
				return true;
			}
		}
	}
	visiting[v] = false;
	visited[v] = true;
	return false;
}

int main()
{
	int t;
	getI(t);
	while(t--)
	{
		int a, b;
		getII(a,b);
		F(i,0,b)
		{
			int x, y;
			getII(x,y);
			AdjList[x].pb(y);
		}
		bool cyc = false;
		FE(i,1,a)
		{
			cyc = cycleFind(a);
			if(cyc)break;
		}
		if(!cyc)
			cout << "NAO" << endl;
		else
			cout << "SIM" << endl;

		toVisit.reset();
		visiting.reset();
		visited.reset();
		F(i,0,AdjList.size())
			AdjList[i].clear();
	}
	return 0;

}