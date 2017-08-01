#include <bits/stdc++.h>

#define bit(x,i) (x&(1<<i))  //select the bit of position i of x

using namespace std;

long long ipow(long long base, long long exp)
{
    long long result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while(n--)
	{
		long long num;
		long long ans = 0;
		cin >> num;
		bitset<64> b(num);
		bool one = false;
		for(int i = 63; i >= 0; --i)
		{
			auto b = b[i];
			cout << b;
			if(b == 1)
				one = true;
			else if(b == 0 && one == true)
				ans += ipow(2, i);
		}
		cout << endl;
		cout << ans << endl;
	}
	return 0;
}