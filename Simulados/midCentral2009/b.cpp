//B

#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << "Gnomes:"<< endl;
	for(int i = 0; i <n; ++i)
	{
		vector<int> vec(3);
		int a, b, c;
		cin >> a >> b >> c;
		vec[0] = a;
		vec[1] = b;
		vec[2] = c;
		sort(vec.begin(), vec.end());
		bool ord = false;
		if(vec[0] == a && vec[1] == b && vec[2] == c)
			ord = true;
		else if(vec[0] == c && vec[1] == b && vec[2] == a)
			ord = true;
		if(ord)
			cout << "Ordered" << endl;
		else
			cout << "Unordered" << endl;
	}
	return 0;

}