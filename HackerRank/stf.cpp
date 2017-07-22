/*input
3 3
0 1 1 1
1 2 2 4
2 0 1 2
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define mt make_tuple
#define mp make_pair

typedef vector<int> vi;
// 			 a - k*x, a,  b,   s,   t
vector<tuple<double, int, int, int, int> > edges;

const int maxn = 1e5 + 10;
const double tol = 1e-7;

int n, m;
vector<int> parent(maxn);
vector<int> rk(maxn, 0);



int find(int x)
{
	if(x != parent[x])
		parent[x] = find(parent[x]);
	return parent[x];
}

void unite(int a, int b)
{
	if(find(a) != find(b))
	{
		if(rk[a] > rk[b]) parent[b] = a;
		else parent[a] = b;	
		if(rk[a] == rk[b]) rk[a]++;
	}
}

tuple<long double, int, int> kruskal(double K)
{
	iota(all(parent), 0);
	fill(all(rk), 0);
	for(auto& p : edges){
		get<0>(p) = (get<1>(p) - K * get<2>(p));	
	} 
	sort(rall(edges));
	double sum = 0;
	int numSum = 0, denomSum = 0;
	for(auto& p : edges)
	{
		if(find(get<3>(p)) != find(get<4>(p)) )
		{
			numSum += get<1>(p);
			denomSum += get<2>(p);
			unite(get<3>(p), get<4>(p));
			sum += get<0>(p);
		}
	}
	return mt(sum, numSum, denomSum);
}

pair<int, int> irreducible(int a, int b)
{
	int d = __gcd(a, b);
	return (d == 1) ? mp(a, b) : mp(a/d, b/d);
}

pair<int, int> binSearch()
{
	double beg = 0, end = 20000010, value = 10000;
	int numSum = 0, denomSum = 0;
	while(end - beg > tol)
	{
		double mid = (beg + end)/2;
		tie(value, numSum, denomSum) = kruskal(mid);
		if(value > 0)
			beg = mid;
		else
			end = mid;
	}
	return irreducible(numSum, denomSum);
}

int main()
{
	int s, t, x, y;
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; ++i)
	{
		cin >> s >> t >> x >> y;
		edges.push_back(mt((double)x/(double)y, x, y, s, t));
	}	
	auto resp = binSearch();
	cout << resp.fi << "/" << resp.se << endl;
	return 0;
}