#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string a;
	string b;
	string c;
	cin >> a;
	cin >> b;
	for(int i = 0; i < a.size(); ++i)
	{
		if(a[i] != b[i])
			c += '1';
		else
			c += '0';
	}
	
	cout << c << endl;
	return 0;
}