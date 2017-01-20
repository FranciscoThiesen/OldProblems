#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
	if(n == 1) return false;
	if(n == 2 || n == 3) return true;
	for(int i = 2; i <= ceil(sqrt(n)); ++i)
		if(n%i == 0)
			return false;
	return true;

}


int main()
{
	int ans = 0;
	unordered_set<int> primes;
	for(int i = 2; i <= 1000 * 1000; ++i)
	{
		if(isPrime(i))
		{
			primes.insert(i);
			cout << i << " ";
		}
	}
	cout << endl;

	for(int i = 2 ; i < 101; ++i)
	{
		bool circ = true;
		string s = to_string(i);
		for(int j = 1; j < s.size(); ++j)
		{
			string k = s;
			rotate(k.begin(), k.begin() + j, k.end());
			int q = stoi(k);
			cout << q << " ";
			if(!isPrime(q))
				circ = false;
		}
		cout << endl;
	}


	cout << ans << endl;
	return 0;
}