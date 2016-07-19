#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <string>
#include <set>
#include <string.h>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

int maxDeep;
string bla;
char str[1000];
void getDeep()
{
	maxDeep = 0; int balance = 0;
	int i = 0; int index = 0;

	while(str[i]!='\0')
	{
		if(str[i]=='[')
		{
			balance++;
		}
		else
		{
			if(maxDeep<balance)
			{
				maxDeep = balance;
			}
			balance--;
		}
		i++;
	}
}



int main()
{
	int N;
	
	scanf("%d", &N);
	string fodase;
	for (int z = 0; z < N; ++z)
	{
		memset(str, 0, sizeof(str));
		if(!z)getline(cin, fodase);
		getline(cin, bla);
		for (int i = 0; i < bla.size(); ++i)
		{
			str[i] = bla[i];
		}
		getDeep();
		int i=0, deep=0; char last='-';
		long long macacos = 0;
		while(str[i]!='\0')
		{
			if(i!=0)
			{
				last = str[i-1];
			}
			if(str[i]=='[')
			{
				if(last == ']')
				{
					macacos -= pow(2, maxDeep-deep);
				}
				deep++;
			}
			else if(str[i]==']')
			{
				if(last=='[')
				{
					macacos += 2 * pow(2, maxDeep-deep);
				}
				else if(last==']')
				{
					macacos += pow(2, maxDeep-deep);	
				}
				deep--;
			}
			i++;
		}
		if(maxDeep==0)
			macacos=1;
		printf("%d ", z+1);

		printf("%lld\n", macacos);
	}
}