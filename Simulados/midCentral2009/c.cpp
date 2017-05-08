#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <string>
using namespace std;
#define pb push_back
#define mp make_pair

int dull[21];
vector<pair<int, string> > prog;
int state[33];
string exec;

int add(int pr, int at)
{
	int resp = at;
	int costPr = prog[pr].first;
	string dullPr = prog[pr].second;

	resp += costPr;

	for(int i = 0; i < dullPr.size(); i++)
	{
		bool find = false;
		for(int j = 0; j < exec.size(); j++)
		{
			if(dullPr[i] == exec[j])
				find = true;
		}

		if(!find)
		{
			resp += dull[dullPr[i] - 'A'];
		}
		exec += dullPr[i];

	}

	return resp;

}

int remove(int pr, int at)
{
	int resp = at;
	int costPr = prog[pr].first;
	string dullPr = prog[pr].second;

	resp -= costPr;

	for(int i = 0; i < dullPr.size(); i++)
	{
		int find = 0;
		int pos;
		for(int j = 0; j < exec.size(); j++)
		{
			if(dullPr[i] == exec[j])
			{
				find++;
				pos = j;
			}
		}

		if(find == 1)
		{
			resp -= dull[dullPr[i] - 'A'];
		}

		exec.erase(exec.begin() + pos);
	}

	return resp;
}

int main()
{
	int n = 1;
	while(n != 0)
	{
		
		cin >> n;
		if(!n)
			break;
		prog.clear();
		exec.clear();

		int p, s;

		cin >> p >> s;

		for(int i = 0; i < n; i++)
		{
			cin >> dull[i];
		}

		for(int i = 0; i < p; i++)
		{
			int a;
			string b;

			cin >> a >> b;

			prog.pb(mp(a, b));
		}

		int resp = 0;
		int respFinal = 0;

		for(int i = 0; i < s; i++)
		{
			int a;
			cin >> a;

			if(a > 0)
			{
				resp = add(a - 1, resp);
				respFinal = max(resp, respFinal);
			}
			else
			{
				resp = remove(abs(a) - 1, resp);
			}


		}

		cout << respFinal << endl;


	}

	return 0;
}