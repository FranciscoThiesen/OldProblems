// long long mat[10010][10010] = {0};
// long long total[10010] = {0};
// int nums[10010] = {0};

// long long best(int i, int j)
// {
// 	if(i == j)
// 	{
		
// 	//	cout << "i " << i << "  j " << j << " retorna " << mat[i][j] << endl;
// 		return mat[i][j];
// 	}
// 	mat[i][j] = max(nums[i] + total[j] - total[i] - best(i+1,j), nums[j] + ( total[j-1] - total[i-1] - best(i, j-1)));
// 	//cout << "i " << i << "  j " << j << " retorna " << mat[i][j] << endl;
// 	return mat[i][j];
// }
// int main()
// {
// 	int n;
// 	while(scanf("%d", &n) != EOF)
// 	{
// 		for(int i = 0; i < n; ++i)
// 		{

// 			scanf("%d", &nums[i]);
// 			if(i == 0)
// 				total[0] = nums[0];
// 			else
// 				total[i] = total[i-1] + nums[i];
// 		}
// 		for(int y = 0; y < n; ++y)
// 			mat[y][y] = nums[y];
// 		cout << best(0, n-1) << endl;
// 	}
	
// 	memset(total, 0, sizeof(total));

// }
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
using namespace std;
#define ll long long 
#define pb push_back
ll mat[10010][10010] = {0};
ll total[10010] = {0};
int nums[10010] = {0};


long long best(int i, int j)
{
	if(i == j)
	{
		
	//	cout << "i " << i << "  j " << j << " retorna " << mat[i][j] << endl;
		return mat[i][j];
	}
	mat[i][j] = max(nums[i] + total[j] - total[i] - best(i+1,j), nums[j] + ( total[j-1] - total[i-1] - best(i, j-1)));
	//cout << "i " << i << "  j " << j << " retorna " << mat[i][j] << endl;
	return mat[i][j];
}
// i + 1, j = k + 1 ;;;; i, j-1 = k
vector<ll> initial;
vector<ll> aux;
int main()
{
	int n;
	ll ans;
	while(scanf("%d", &n) != EOF)
	{
		for(int i = 0; i < n; ++i)
		{

			scanf("%d", &nums[i]);
			if(i == 0)
				total[0] = nums[0];
			else
				total[i] = total[i-1] + nums[i];
		}
		
		for(int y = 0; y < n; ++y)
			initial.pb(nums[y]);
		
		for(int k = 0; k < initial.size()-1; ++k)
		{
			//cout << "initial   " << initial[k+1] << "  " << initial[k] << endl;
			ans = max(nums[k] + total[initial.size()+k] - total[k] - initial[k], nums[initial.size()+k] + (total[initial.size()+k-1] - total[k-1] - initial[k+1]));
			aux.pb(ans);
			//cout << ans << " ";
		}
		cout << endl;

		while(true)
		{
			initial = aux;
			aux.clear();
			cout << initial.size() << "xerebecanto" << endl;
			for(int k = 0; k < initial.size()-1; ++k)
			{

				//cout << "initial   " << initial[k+1] << "  " << initial[k] << endl;
				ans = max(nums[k] + total[initial.size()+k] - total[k] - initial[k+1], nums[initial.size()+k] + (total[initial.size()+k-1] - total[k-1] - initial[k]));
				aux.pb(ans);
				//cout << ans << " ";
			}
			for(auto& p : aux)
				cout << p << " ";
			cout << endl;
			if(aux.size() == 1)
			{
				cout << aux[0] << endl;
				break;
			}
			initial.clear();
		}
		aux.clear();
		initial.clear();

		
	}
}