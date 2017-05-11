#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair

int main()
{
	int n;
	cin >> n;
	vector<string> names;
	int g = 0, b = 0;
	for(int i = 0; i < n; ++i)
	{
		char c; string s;
		cin >> c;
		cin >> s;
		names.pb(s);
		if(c == '+')
			g++;
		else
			b++;
	}
	sort(names.begin(), names.end());
	for(auto& p : names)
		cout << p << endl;
	cout << "Se comportaram: " << g << " | Nao se comportaram: " << b << endl;
	return 0;
}