#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

int main()
{
	int n;
	cin >> n;
	unordered_map<string, unordered_set<string> > g;
	for(int i = 0; i < n; ++i)
	{
		string a, b, c, d;
		cin >> a >> b >> c >> d;
		g[a].insert(b);
		g[a].insert(c);
		g[a].insert(d);
	}
	string line;
	cin.ignore();
	while(getline(cin, line))
	{
		string x, y;
		bool fi = true;
		for(int i = 0; i < line.size(); ++i)
		{
			if(line[i] != ' ' && fi)
				x+=line[i];
			else if(line[i] != ' ' && !fi)
				y += line[i];
			else
				fi = false;
		}
		if(g[x].find(y) == g[x].end())
			cout << "Tente Novamente!" << endl;
		else
			cout << "Uhul! Seu amigo secreto vai adorar o/" << endl;
		
	}
	return 0;
}