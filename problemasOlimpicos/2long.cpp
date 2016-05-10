#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
//#include <boost>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<string> V(n);
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if(s.size() > 10)
		{
			printf("%c%lu%c\n", s.front(), s.length() - 2, s.back());
			string a = "";
			a.push_back(s.front());
			auto y = s.length() - 2;
			a.append(y);
			a.push_back(s.back());
			V.push_back(a);
		}
		else
			V.push_back(s);
	}
	for(auto& str : V)
	{
		cout << str << endl; 
	}
	return 0;
}