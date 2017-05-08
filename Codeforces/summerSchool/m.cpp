#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;
typedef vector<ll> vll;
typedef vector<ull> vull;

//Complexidade de O(nC)
//No problema N temos n <= 50, e C <= 500000
 
vector<bool> prime(500001, true);
vector<int> primu;

ll count(vector<int>& vec)
{
    int i, j, x, y;
 	int n = primu[primu.size()-1];
 	long long ret = 0;
 	int m = vec.size();
    // We need n+1 rows as the table is consturcted in bottom up manner using 
    // the base case 0 value case (n = 0)
   // int table[n+1][m];

    ll table[m+1][n+1];
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<=m; i++)
        table[i][0] = 1;
 	
 	for(i = 0; i < n+1;++i)
 		table[0][i] = 0;
 	table[0][0] = 1;

    // Fill rest of the table enteries in bottom up manner  
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j < n+1; j++)
    	{
            // Count of solutions including S[j]
            x = (j-vec[i-1] >= 0)? table[i-1][j - vec[i-1]]: 0;
 			
            // Count of solutions excluding S[j]
            y = table[i-1][j];
 			//y = 0;
            // total count
            table[i][j] = x + y;
        }
    }
    // for(i = 0; i <= m; ++i)
    // {
    // 	for(j = 0; j < n+1; ++j)
    // 	{
    // 		cout << table[i][j] << " ";
    // 	}
    // 	cout << endl;
    // }
    for(int i = 0; i < primu.size(); ++i)
    	ret += table[m][primu[i]];

    return ret;
}


 
void sieve(ll n)
{
	prime[0] = prime[1] = false;
	for(ll i = 2; i*i <= n; ++i)
	{
		if(prime[(int)i])
		{
			if(i <= n)
			{
				for(ll j = i*i; j <=n; j+=i)
				{
					prime[(int)j] = false;
				}
			}
		}
	}
	for(int i = 2; i <= n; ++i)
	{
		if(prime[i])
		{
			primu.pb(i);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> nums;
	map<int, int> p;
	int largestSum = 0;
	for(int i = 0; i <n; ++i)
	{
		int x;
		scanf("%d", &x);
		p[x]++;
	}
	for(auto& q : p)
	{
		if(q.se >= 1)
		{
			for(int i = 1; i <= q.se; ++i)
			{
				nums.pb(q.fi * i);
			}
		}
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	for(auto& p : nums)
		cout << p << " ";
    int qntd;
    sieve(largestSum);
    for(auto& p : primu)
    	cout << p << " ";
 	cout << "creu " << endl;
    cout << endl;
    printf("%lld\n", count(nums));
    return 0;
}