#include <iostream>
#include <string>

using namespace std;
int main()
{
	string x;
	string y;
	std::cin >> x;
	std::cin >> y;
	for(int i = 0; int < x.size(); i++)
	{
		if(x[i] <= 'Z')
			x[i] = x[i] + 32;
		if(y[i] <= 'Z')
			y[i] = y[i] + 32;
		if(x[i] > y[i])
		{
			std::cout << "1" << std::endl;
			return 0;
		}
		if(x[i] < y[i])
		{
			std::cout << "-1" << std::endl;
			return 0;
		}
	}
	std::cout << "0" << std::endl;

}