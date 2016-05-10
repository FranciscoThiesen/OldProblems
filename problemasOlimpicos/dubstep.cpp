#include <string>
#include <cstdio>
#include <iostream>

using namespace std;
int main()
{
	string x;
	cin >> x;
	string y;
	int wub = 0;
	for(int i = 0; i < x.size(); i++)
	{
		if(x[i] == 'W' && x[i+1] == 'U')
		{
			if(x[i + 2] == 'B')
			{
				i += 2;
				wub++;
			}
			else
				y+= x[i];
		}
		else
			if(wub >= 0)
			{
				y += x[i];
				if(x[i + 1] == 'W' && x[i+2] == 'U')
				{
				if(x[i + 3] == 'B')
				{
					y += ' ';
				}
			}
			}	
			else
			{
				y += x[i];
			}
	}
	cout << y << endl;
	return 0;
}