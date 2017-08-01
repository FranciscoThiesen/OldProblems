// https://www.codechef.com/APRIL17/problems/CLIQUED
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <limits>
 
 
using namespace std;
 
typedef long long ll;
 
#define sz(v) (v).size()
#define eb emplace_back
#define mp make_pair
#define emp emplace
#define fi first
#define se second
#define sc(a) cin >> a
#define sc2(a, b) cin >> a >> b
#define sc3(a,b,c) cin >> a >> b >> c
#define sc4(a,b,c,d)cin >>a >> b >> c >> d
#define sc5(a,b,c,d,e)cin >> a >> b >> c >> d >> e
 
bool muda(int j, ll nd, ll *resp)
{
  if(nd >= *(resp))return false;
  *resp = nd;
  return true;
}
 
constexpr ll mxll = numeric_limits<ll>::max();
 
vector<ll> dk(vector<vector<pair<int, ll> > >& grafo, int beg, int k, ll x) 
{
  int n = sz(grafo);
  vector<ll> resp(n, mxll);
  priority_queue<pair<ll, int>> pq;
 
  pq.push(mp(0, beg));
  resp[beg] = 0;
  bool fi = true;
  
  while (!pq.empty()) 
  {
    int i = pq.top().se;
    ll d = -pq.top().fi;
 
    pq.pop();
    if (d != resp[i]) 
      continue;
    for (auto v : grafo[i])
    {
     if(muda(v.fi, d + v.se, &resp[v.fi]))
     {
      pq.push(mp(- (d + v.se), v.fi));
     }
    }
    if (i < k && fi) 
    {
      fi = false;
      for (int j = 0; j < k; j++)
      {
       if(muda(j, d + x, &resp[j]))
       {
        pq.push(mp(- (d+x), j));
       }
      }
    }
  }
  return resp;
}
 
void _42() 
{
  int n, k, m, s;ll x;
  sc5(n,k,x,m,s);
  s--;
  vector<vector<pair<int, ll> > > grafo(n);
  while (m--) 
  {
    ll a, b, c;
    sc3(a,b,c);
    grafo[a-1].eb(b-1, c);
    grafo[b-1].eb(a-1, c);
  }
  vector<ll> resp = dk(grafo, s, k, x);
  for (auto& p : resp) cout << p << " ";
  cout << endl;
}
 
int main() 
{
  int t;
  sc(t);
  while (t--) 
    _42();
  return 0;
}