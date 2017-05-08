#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <utility>
#include <cmath>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
	string s, k;
	cin >> s >> k;
	unsigned long long num = 0;
	bool findP = false;
	int pp = -1;
	int pk = -1;
	string noS, noK;
	for(int i = 0; i < s.size(); ++i)
	{
		if(s[i] == '.')
		{
			findP = true;
			pp = i;
		}
		else
			noS.push_back(s[i]);
	}
	findP = false;
	for(int i = 0; i < k.size(); ++i)
	{
		if(k[i] == '.')
		{
			findP = true;
			pk= i;
		}
		else
			noK.push_back(k[i]);
	}
	int fact = 0;
	int fact2 = 0;
	if(pp != -1)
	{
		fact = s.size() - pp - 1;
	}
	if(pk != -1)fact2 = k.size() - pk - 1;
	unsigned long long n = stoull(noS);
	unsigned long long n2 = stoull(noK);
	int mult = max(fact, fact2);
	if(fact > fact2)
	{
		for(int i = 0; i < fact-fact2; ++i)
		{
			n2 *= 10;
		}
	}
	else if(fact2 > fact)
	{
		for(int i = 0; i < fact2 - fact; ++i)
		{
			n *= 10;
		}
	}
	cout << n/n2 << endl;
	return 0;

}