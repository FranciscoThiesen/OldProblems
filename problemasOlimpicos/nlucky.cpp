#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int main()
{
	string s;
	cin >> s;
	int counter = 0;
	for(int j = 0; j < s.length(); j++)
	{
		if(s[j] == '4' || s[j] == '7')
			counter++;
	}
	string w = patch::to_string(counter);
	for(int i = 0; i < w.length(); i++)
	{
		if(w[i] != '4' && w[i] != '7')
		{	
			printf("NO\n");
			return 1;
		}

	}
	printf("YES\n");
	return 0;
}