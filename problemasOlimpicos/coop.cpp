#include <set>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int x;
	scanf("%d",&x);
	set<char> a;
	int total = 0;
	string k;
	string q;
	string f;
	getline(cin, k);
	getline(cin, q);
	getline(cin, f);
	for(int i = 0; i < q.size();++i)
	{
		if(k[i] != ' ')
			a.insert(k[i]);
		if(q[i] != ' ')
			a.insert(q[i]);
		if(f[i] != ' ')
			a.insert(f[i]);
	}	

	for(auto& p : a)
		total++;
	if(total >= x + 1)
	{
		printf("I become the guy.\n");
		return 0;
	}
	else
		printf("Oh, my keyboard!\n");
	return 0;
}
	