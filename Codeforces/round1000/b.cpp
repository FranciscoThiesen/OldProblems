#include <bits/stdc++.h>

using namespace std;

int main()
{
	set<string> pal;
	string p;
	cin >> p;
	for(int i = 0; i < 1000;++i)
	{
		string aux;
		for(int j = 1; j < p.size(); ++j)
		{
			aux += p[j];
		}
		aux += p[0];
		pal.insert(aux);
		p = aux;
	}
	cout << pal.size() << endl;
	return 0;
}