#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;
int main()
{
	int n = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		string x;
		string y;
		scanf("%s", &x);
		scanf("%s", &y);
		x.reverse();
		y.reverse();
		int a = stoi(x.c_str()) + stoi(y.c_str());
		printf("%d", a);	
	}
}