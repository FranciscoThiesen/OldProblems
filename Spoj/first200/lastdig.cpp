#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
	long long a,b,t,x;
	cin >> t;
	for(int s = 0; s < t; s++)
	{
		scanf("%lld%lld",&a,&b);
		int q = b%4;
		if(b == 0)
		{
			cout << 1 << endl;
			continue;
		}
		else if(q == 0)
			x = pow(a,4);
		else
			x = pow(a,q);
		string res = to_string(x);
		cout << res.back() << endl;
	}
	return 0;}