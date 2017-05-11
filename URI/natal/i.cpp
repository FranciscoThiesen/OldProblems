#include <bits/stdc++.h>
using namespace std;

int main()
{
	//s::sync_with_stdio(0);
	//n.tie(0);
	int n;
	cin >> n;
	unordered_map<string, string> translate;
	for(int i = 0; i < n; ++i)
	{
		string a, b;
		cin >> a;
		cin.ignore();
		getline(cin, b);
		translate[a] = b;
	}
	int k;
	cin >> k;
	cin.ignore();
	for(int i = 0; i < k; ++i)
	{
		string name;
		getline(cin, name);
		string lang;
		cin >> lang;
		cin.ignore();
		cout << name << endl;
		cout << translate[lang] << endl;
		cout << endl;
	}
	return 0;
}