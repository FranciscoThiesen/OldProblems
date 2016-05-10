#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int main()
{
	string n;
	string p;
	string original;
	cin >> n;
	cin >> p;
	cin >> original;
	string a = p + n;
	sort(a.begin(),a.end());
	sort(original.begin(),original.end());
	int comparer = 0;
	if(original.size() > a.size())
	{
		printf("NO\n");
		return 0;
	}
	for( int i = 0; i < a.size(); i++)
	{
		if(comparer == a.size() - 1)
		{
			cout << "YES" << endl;
			return 0;
		}
		if(a[i] != original[i])
		{
			cout << "NO" << endl;
			return 0;
		}
		else
			comparer++;
	}
	return 0;
	
}