#include <string>
#include <iostream>

int main()
{
	std::string x;
	std::cin >> x;
	if(x[0] >= 'a' && x[0] <= 'z')
		x[0] = x[0] - 32;
	std::cout << x << std::endl;
	return 0;
}