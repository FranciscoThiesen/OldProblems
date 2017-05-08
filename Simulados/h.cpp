#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <map>
#include <set>
#include <iterator>
#include <list>

using namespace std;

#define pb push_back
#define mp make_pair
map<int, int> homem;
map<int, int> elefante;
map<int, int> rato;



void move(int x, int y)
{
	if(y > x )
		return;
	list< map<int,int>::iterator > il;
	for(auto& p : homem)
	{
		if(x == p.first)
		{
			if(y == p.second)
			{
				il.pb(p);
				elefante.insert(mp(x, y));
			}
			else if(y > p.second)
			{
				elefante.insert(mp(x, p.second));
				move(p.second+1, y);
				il.pb(p);
			}
			else
			{
				elefante.insert(mp(x, y));
				homem.insert(mp(y+1, p.second));
				il.pb(p);
			}

		}
		else if(x == p.second)
		{
			homem.insert(mp(p.first, p.second-1));
			il.pb(p);
			elefante.insert(mp(x,x));
			move(x+1, y);
		}
		else if(x > p.first && x < p.second)
		{
			if(y == p.second)
			{
				homem.insert(mp(p.first, x-1));
				elefante.insert(mp(x, y));
				il.pb(p);
			}
			else if(y > p.second)
			{
				homem.insert(p.first, x-1);
				elefante.insert(mp(x, p.second));
				move(p.second+1, y);
				il.pb(p);
			}
			else if(y < p.second)
			{
				homem.insert(mp(p.first, x-1));
				elefante.insert(mp(x, y));
				homem.insert(mp(y+1, p.second));
			}
		}
		else if(y == p.first)
		{

			elefante.insert(mp(y, y));
			homem.insert(mp(y+1, p.second));
			il.pb(p);
			move(x, y-1);
		}
		else if(y > p.first && y <= p.second)
		{
			elefante.insert(mp(p.first, y));
			homem.insert(mp(y+1, p.second));
			int xx = p.first;
			il.pb(p);
			move(x, p.first-1);
		}
		for(auto i : il)
    		homem.erase(*i);
    	il.clear();
	}
	for(auto& p : elefante)
	{
		if(x == p.first)
		{
			if(y == p.second)
			{
				il.pb(p);
				rato.insert(mp(x, y));
			}
			else if(y > p.second)
			{
				rato.insert(mp(x, p.second));
				move(p.second+1, y);
				il.pb(p);
			}
			else
			{
				rato.insert(mp(x, y));
				elefante.insert(mp(y+1, p.second));
				il.pb(p);
			}

		}
		else if(x == p.second)
		{
			elefante.insert(mp(p.first, p.second-1));
			il.pb(p);
			rato.insert(mp(x,x));
			move(x+1, y);
		}
		else if(x > p.first && x < p.second)
		{
			if(y == p.second)
			{
				elefante.insert(mp(p.first, x-1));
				rato.insert(mp(x, y));
				il.pb(p);
			}
			else if(y > p.second)
			{
				elefante.insert(p.first, x-1);
				rato.insert(mp(x, p.second));
				move(p.second+1, y);
				il.pb(p);
			}
			else if(y < p.second)
			{
				elefante.insert(mp(p.first, x-1));
				rato.insert(mp(x, y));
				elefante.insert(mp(y+1, p.second));
			}
		}
		else if(y == p.first)
		{

			rato.insert(mp(y, y));
			elefante.insert(mp(y+1, p.second));
			il.pb(p);
			move(x, y-1);
		}
		else if(y > p.first && y <= p.second)
		{
			rato.insert(mp(p.first, y));
			elefante.insert(mp(y+1, p.second));
			int xx = p.first;
			il.pb(p);
			move(x, p.first-1);
		}
		for(auto i : il)
    		elefante.erase(*i);
    	il.clear();
	}
	for(auto& p : rato)
	{
		if(x == p.first)
		{
			if(y == p.second)
			{
				rato.erase(p);
				il.pb(p);
				homem.insert(mp(x, y));
			}
			else if(y > p.second)
			{
				homem.insert(mp(x, p.second));
				move(p.second+1, y);
				il.pb(p);
			}
			else
			{
				homem.insert(mp(x, y));
				rato.insert(mp(y+1, p.second));
				il.pb(p);
			}

		}
		else if(x == p.second)
		{
			rato.insert(mp(p.first, p.second-1));
			il.pb(p);
			homem.insert(mp(x,x));
			move(x+1, y);
		}
		else if(x > p.first && x < p.second)
		{
			if(y == p.second)
			{
				rato.insert(mp(p.first, x-1));
				homem.insert(mp(x, y));
				il.pb(p);
			}
			else if(y > p.second)
			{
				rato.insert(p.first, x-1);
				homem.insert(mp(x, p.second));
				move(p.second+1, y);
				il.pb(p);
			}
			else if(y < p.second)
			{
				rato.insert(mp(p.first, x-1));
				homem.insert(mp(x, y));
				rato.insert(mp(y+1, p.second));
			}
		}
		else if(y == p.first)
		{

			homem.insert(mp(y, y));
			rato.insert(mp(y+1, p.second));
			il.pb(p);
			move(x, y-1);
		}
		else if(y > p.first && y <= p.second)
		{
			homem.insert(mp(p.first, y));
			rato.insert(mp(y+1, p.second));
			int xx = p.first;
			il.pb(p);
			move(x, p.first-1);
		}
		for(auto i : il)
    		rato.erase(*i);
    	il.clear();
	}
	return;
}
int main()
{
	int n, op;
	while(scanf("%d %d", &n, &op) != EOF)
	{
		homem.clear();
		elefante.clear();
		rato.clear();
		homem.insert(mp(0, n-1));
		for(int i = 0; i < op; ++i)
		{
			int x, y;
			char c;
			cin >> c >> x >> y;
			x--, y--;
			if(c == 'C')
			{
				int hom = 0;
				int ele = 0;
				int rat = 0;
				for(auto& p : homem)
				{
					if(x >= p.first && x <= p.second)
					{
						hom += (min(y,p.second) - x) + 1;
					}
					else if(y >= p.first && y <= p.second)
					{
						hom += y - max(x, p.first) + 1;
					}
				}
				for(auto& q : elefante)
				{
					if(x >= q.first && x <= q.second)
					{
						ele += (min(y,q.second) - x) + 1;
					}
					else if(y >= q.first && y <= q.second)
					{
						ele += y - max(x, q.first) + 1;
					}
				}
				for(auto& r : rato)
				{
					if(x >= r.first && x <= r.second)
					{
						rat += (min(y,r.second) - x) + 1;
					}
					else if(y >= r.first && y <= r.second)
					{
						rat += y - max(x, r.first) + 1;
					}
				}
				printf("%d %d %d\n", hom, ele, rat);
			}
			else
				move(x, y);
		}
	}
	return 0;
}