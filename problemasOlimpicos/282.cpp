#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;
int main()
{
	int x, y = 0;
	multiset<int> operations;
	scanf("%d", &x);
	vector<string> ops;
	for(int i = 0; i < x;i++)
	{
		string a;
		cin >> a;
		for(int b = 0; b < a.size(); b++)
			operations.insert(a[b]);
	}
	int a = operations.count('+');
	int b = operations.count('-');
	y += a/2;
	y -= b/2;
	printf("%d\n", y);
	return 0;

}