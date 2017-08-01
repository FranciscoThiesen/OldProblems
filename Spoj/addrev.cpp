#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		string a, b;
		cin >> a;
		cin >> b;
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		int x = stoi(a);
		int y = stoi(b);
		int z = x + y;
		string result;
		result = to_string(z);
		reverse(result.begin(), result.end());
		int p = stoi(result);
		cout << p << endl;

	}
	return 0;
}
