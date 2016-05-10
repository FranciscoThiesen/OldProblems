#include <string>
#include <iostream>

using namespace std;
int main()
{
	string x;
	std::cin >> x;
	int h,e,l1,l2,o = 0;
	for(int i = 0; i < x.size(); i++)
	{
		if(x[i] == 'h')
		{
			h = i;
			cout << "h";
			break;
		}
	}
	for(int j = h + 1; j < x.size(); j++)
	{
		if(x[j] == 'e')
		{
			e = j;
			cout << "e";
			break;
		}
	}
	for(int k = e + 1; k < x.size(); k++)
	{
		if(x[k] == 'l')
		{
			l1 = k;
			cout << "l1";
			break;
		}
	}
	for(int q = l1 + 1; q < x.size(); q++)
	{
		if(x[q] == 'l')
		{
			l2 = q;
			cout << "l2";
			break;		
		}
	}
	for(int v = l2 + 1; v < x.size(); v++)
	{
		if(x[v] == 'o')
		{
			o = v;
			return 0;
			break;
		}
	}	
	printf("NO\n");
	return 0;
	
	
}