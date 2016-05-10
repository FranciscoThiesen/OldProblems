#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	unsigned long long int x;
	cin >> x;
	unsigned long long int comp = 1;
	for(int i = 0; i < 1000000;i++)
	{
		unsigned long long int amplitude = 5*pow(2,i);
		if( x >= comp && x < comp + amplitude)
		{
			if(x >= comp && x < comp + amplitude/5)
				printf("Sheldon\n");
			if(x >= comp + amplitude/5 && x < comp + (2*amplitude/5))
				printf("Leonard\n");
			if(x >= comp + (2*amplitude/5) && x < comp + 3*amplitude/5)
				printf("Penny\n");
			if(x >= comp + (3*amplitude/5) && x < comp + 4*amplitude/5)
				printf("Rajesh\n");
			if(x >= comp + (4*amplitude/5) && x < comp + amplitude)
				printf("Howard\n");
			return 0;
		}
		comp += amplitude;
	}
	return 1;
}