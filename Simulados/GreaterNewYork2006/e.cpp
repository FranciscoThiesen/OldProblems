#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <set>
#include <string.h>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
vector<int> operations;

void solve(vector<pair<int, int> >& pilia)
{
	int tamanho = pilia.size();
	for(int i = 1; i <= tamanho; ++i)
	{
		int pos;
		for(int j = 0; j < tamanho; ++j)
		{
			if(pilia[j].first == i)
				pos = j;
		}
		//cout << "a posissaum do " << i << " eh " << pos << endl;
		if(pos != tamanho-i || pilia[pos].se > 0)
		{
			if(!(pos == 0 && pilia[pos].se > 0))
			{	
				operations.pb(pos+1);
				//cout << "operacao " << pos+1 << endl;
				reverse(pilia.begin(), pilia.begin() + (pos) + 1);
				for(int k = 0; k <= pos; ++k)
				{
					if(pilia[k].se > 0)
						pilia[k].se -= 2;
					else
						pilia[k].se += 2;
				}
				if(pilia[0].se == -1)
				{
					operations.pb(1);
					pilia[0].se += 2;
				}
				
			}
			reverse(pilia.begin(), pilia.begin() + (tamanho-i) + 1);
			operations.pb(tamanho-i + 1);
			//cout << "operereca " << tamanho - i + 1 << endl;
			for(int k = 0; k < tamanho-i+1; ++k)
			{
				if(pilia[k].se > 0)
					pilia[k].se -= 2;
				else
					pilia[k].se += 2;
			}
			
		}
	}

}
int main()
{
	int t;
	cin >> t;
	int test = 1;
	while(t--)
	{
		int n;
		cin >> n;
		vector<pair<int, int> > pilha;
		for(int i = 0; i < n; ++i)
		{
			string a;
			string b;
			cin >> a;
			char sinal = a[0];
			for(int j = 1; j < a.size(); ++j)
				b += a[j];
			int num = stoi(b);
			if(sinal == '+')
				pilha.pb(mp(num,1));
			else
				pilha.pb(mp(num,-1));
			//cout << sinal << num << endl;
		}
		if(pilha.size() == 1)
		{
			if(pilha[0].se < 0)
				cout << test << " " << 1 << " " << 1 << endl;
			else
				cout << test << " " << 0 << endl;
		}
		else
		{
			solve(pilha);
			operations.pb(pilha.size());
			cout << test << " " << operations.size() << " ";
			for(auto& p : operations)
			{
				cout << p << " ";
			}
			cout << endl;
		}
		operations.clear();
		test++;
	}
	return 0;
}