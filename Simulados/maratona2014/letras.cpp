// Letras
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iterator>
#include <string>
#include <cstring>

#define gcd __gcd
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<double> vd;

char mat[100][100];
vvi adjList(10000);

vi visitado(10000, 0);
vi dist(10000, -1);
vector<char> letras;
unordered_set<char> let;
//set<char> let;

void dfs(int vertice, unordered_set<char> let, vi visitado)
{
//   for(int i = 0; i < 4; i++)
//   {
//     int x1 = p.fi + dir[i].fi;
//     int y1 = p.se + dir[i].se;
//      if(x1 >= 0 && x1 < N && y1 >= 0 && y1 < N && mat[x1][y1] )
//     {
      
//     }
//   }
  for(auto& p : adjList[vertice])
  {
    char busca;
    if(letras[p] >= 'A' && letras[p] <= 'Z')
    {   
      busca = letras[p] + 32; 
    }
    else
      busca = letras[p] - 32;
      
    auto it = let.find(busca);
    if(visitado[p] == 0 && it == let.end())
    {
      if(dist[p] == -1)
        dist[p] = dist[vertice] + 1;
      else
        dist[p] = min(dist[p], dist[vertice] + 1);
      let.insert(letras[p]);
      visitado[p] = 1;
      dfs(p, let, visitado);
    }
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  for(int y = 0; y < n; ++y)
  {
    for(int x = 0; x < n; ++x)
    {
      char c;
      cin >> c;
      mat[x][y] = c;
      letras.pb(mat[x][y]);
    }
    cout << endl;
  }

  
  for(int y = 0; y < n-1; ++y)
  {
    for(int x = 0; x < n-1; ++x)
    {
      adjList[x + n*y].pb(x+1 + n*y);
      adjList[x+1 + n*y].pb(x + n*y);
      adjList[x + n*y].pb(x + n*(y+1));
      adjList[x + n*(y+1)].pb(x + n*y);
    }
  }
  
  for(int x = 0; x < n - 1; x++)
  {
    adjList[x + n * (n - 1)].pb(x+1 + n*(n - 1));
    adjList[x+1 + n*(n-1)].pb(x + n * (n - 1));
  }
  
  for(int y = 0; y < n - 1; y++)
  {
    adjList[n - 1 + n * y].pb(n - 1 + n * (y + 1));
    adjList[n - 1 + n * (y + 1)].pb(n - 1 + n * y);
  }
  
  dist[0] = 0;
  let.insert(letras[0]);
  visitado[0] = 1;
  dfs(0, let, visitado);
  
  cout << dist[n*n - 1] << endl;
  
    return 0;
}
