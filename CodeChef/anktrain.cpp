// https://www.codechef.com/DEC16/problems/ANKTRAIN
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		if(k%8 == 1)
			cout << k + 3 << "LB" << endl;
		else if(k%8 == 4)
			cout << k - 3 << "LB" << endl;
		else if(k%8 == 3)
			cout << k + 3 <<  "UB" << endl;
		else if(k%8 == 6)
			cout << k - 3 << "UB" << endl;
		else if(k%8 == 0)
			cout << k -1 << "SL" << endl;
		else if(k%8 == 7)
			cout << k + 1 << "SU" << endl;
		else if(k%8 == 5)
			cout << k -3 <<  "MB" << endl;
		else if(k%8 == 2)
			cout << k + 3 << "MB" << endl;
	}
	return 0;
}	 