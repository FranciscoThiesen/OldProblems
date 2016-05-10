#include <cstdio>
#include <iostream>
int main()
{
	long long int x;
	std::cin >> x;
	long long int total = 0;
	for(long long int a = 1; a <= x; a++)
	{
		if(a < 10)
			total++;
		else if(a < 100)
			total += 2;
		else if(a < 1000)
			total += 3;
		else if(a < 10000)
			total += 4;
		else if(a < 100000)
			total += 5;
		else if(a < 1000000)
			total += 6;
		else if(a < 10000000)
			total += 7;
		else if(a < 100000000)
			total += 8;
		else if(a < 1000000000)
			total += 9;
		else if(a < 10000000000)
			total += 10;
	}
	std::cout << total << std::endl;
}