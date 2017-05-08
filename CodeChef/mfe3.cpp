/*input
5 1
1 2 2 2 2
1 5 3
*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <vector>
#include <utility>
#include <deque>
#include <tuple>
#include <algorithm>
#include <set>
#include <iterator>
#include <deque>
#include <cmath>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define MAXN 100001
#define forn(i, v) for(int (i) = 0; (i) < (v); ++(i))
#define mt make_tuple

typedef pair<int, int> ii;
vector<int> elems(MAXN);
multiset<ii> cur;
deque<ii> d; 
int sz;

int n;
int S;

bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
{
	if (get<0>(a)/S != get<0>(b)/S) return get<0>(a)/ S < get<0>(b)/ S;
  	return get<1>(a) < get<1>(b);
}


// the idea is a deque with pair<frequency, number> and a multiset<pair<int, int> > the pair order is also freq, num

void remove_beg(int qntd)
{
	while(qntd > 0)
	{
		ii u = d.front();
		if(qntd < u.fi)
		{
			cur.insert(mp(u.fi - qntd, u.se));
			cur.erase(cur.find(mp(u.fi, u.se)));
			d.front().fi = u.fi - qntd;
			break;
		}
		else if(qntd == u.fi)
		{
			cur.erase(cur.find(mp(u.fi, u.se)));
			d.pop_front();
			break;
		}
		cur.erase(cur.find(mp(u.fi, u.se)));
		d.pop_front();
		qntd -= u.fi;
	}
}

void remove_end(int qntd)
{
	while(qntd > 0)
	{
		ii u = d.back();
		if(qntd < u.fi)
		{
			cur.insert(mp(u.fi - qntd, u.se));
			cur.erase(cur.find(mp(u.fi, u.se)));
			d.back().fi = u.fi - qntd;
			break;
		}
		else if(qntd == u.fi)
		{
			cur.erase(cur.find(mp(u.fi, u.se)));
			d.pop_back();
			break;
		}
		cur.erase(cur.find(mp(u.fi, u.se)));
		d.pop_back();
		qntd -= u.fi;
	}
}

void insert_beg(int idx, int qntd)
{
	vector<ii> freqElem;
	int ant = elems[idx];
	int qnt = 1;
	for(int i = idx+1; i < idx + qntd; ++i)
	{
		if(elems[idx] != ant)
		{
			freqElem.pb(mp(qnt, ant));
			ant = elems[idx];
			qnt = 1;
		}
		else
		{
			qnt++;
		}
	}
	freqElem.pb(mp(qnt, ant));
	int sz = freqElem.size();
	for(int i = sz-1; i >= 0; --i)
	{
		if(i == sz-1)
		{
			if(d.front().se == freqElem[i].se)
			{
				cur.erase(cur.find(mp(d.front().fi, d.front().se)));
				cur.insert(mp(d.front().fi + freqElem[i].fi, d.front().se));
				d.front().fi += freqElem[i].se;
			}
			else
			{
				cur.insert(mp(freqElem[i].fi, freqElem[i].se));
				d.push_front(mp(freqElem[i].fi,  freqElem[i].se));
			}
		}
		else
		{
			cur.insert(mp(freqElem[i].fi, freqElem[i].se));
			d.push_front(mp(freqElem[i].fi,  freqElem[i].se));
		}
	}
}

void insert_back(int idx, int qntd)
{
	vector<ii> freqElem;
	int ant = elems[idx];
	int qnt = 1;
	for(int i = idx+1; i < idx + qntd; ++i)
	{
		if(elems[idx] != ant)
		{
			freqElem.pb(mp(qnt, ant));
			ant = elems[idx];
			qnt = 1;
		}
		else
		{
			qnt++;
		}
	}
	freqElem.pb(mp(qnt, ant));
	int sz = freqElem.size();
	for(int i = 0; i < sz; ++i)
	{
		if(i == 0)
		{
			if(d.back().se == freqElem[i].se)
			{
				cur.erase(cur.find(mp(d.back().fi, d.back().se)));
				cur.insert(mp(d.back().fi + freqElem[i].fi, d.back().se));
				d.back().fi += freqElem[i].se;
			}
			else
			{
				cur.insert(mp(freqElem[i].fi, freqElem[i].se));
				d.push_back(mp(freqElem[i].fi,  freqElem[i].se));
			}
		}
		else
		{
			cur.insert(mp(freqElem[i].fi, freqElem[i].se));
			d.push_back(mp(freqElem[i].fi,  freqElem[i].se));
		}
	}
}

int main()
{
	int q;
	cin >> n >> q;
	S = floor(sqrt(n));
	forn(i, n) cin >> elems[i];
	vector<tuple<int, int, int> > qry;
	forn(j, q)
	{
		int x, y, z;
		cin >> x >> y >> z;
		qry.pb(mt(x, y, z));
	}
	sort(qry.begin(), qry.end(), cmp);
	int l, r = -1;
	for(auto& p : qry)
	{
		int left = get<0>(p);
		int right = get<1>(p);
		int freq = get<2>(p);
		if(l + r == -2)
		{
			d.push_back(mp(1, elems[left]));
			cur.insert(mp(1, elems[left]));
			insert_back(left, right - left);
			l = left;
			r = right;
		}
		if(l > left)
		{
			remove_beg(l - left);
		}
		else if(l < left)
		{
			insert_beg(l-1, left - l);
		}
		if(r > right)
		{
			insert_back(right, r-right);
		}
		else if(r < right)
		{
			remove_end(right - r);
		}
		l = left;
		r = right;
		auto mx = *(cur.rbegin());
		if(mx.fi >= freq)
		{
			cout << mx.se << endl;
		}
		else
			cout << -1 << endl;
	}
	return 0;
}