#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <iterator>
#include <utility>
#include <cstdio>
#include <cstring>

using namespace std;


int prime[500001];
long long dp[2][500011];//guardando apenas o estado n-1 e n, porque se nao tomo tle


long long getCount(vector <int> bag) 
{
   long long res = 0;
   sort(bag.begin(),bag.end());
   // crivo para gerar os primos ate 5 * (10^5) -> Complexidade O(n log log n)
   memset(prime,1,sizeof(prime));
   prime[0] = prime[1] = 0;
   for (int i = 2; i * i <= 500000; i++) {
      if (prime[i]) {
         for (int j = i * i; j <= 500000; j += i) {
            prime[j] = 0;
         }
      }
   }

   // quantoas vezes cada elemento apareceu? tratando duplicatas
   map<int,int> freq;
   for (int i = 0; i < bag.size(); i++) 
      freq[bag[i]]++;
   

   int kth = 1;
   
   // caso base
   dp[0][0] = 1;

   //dp[n][k] = quantas sub bags conseguimos construir usando os elementos ate 1..n bags que somam exatamente k
   
   for (auto it = freq.begin(); it != freq.end(); it++, kth++) 
   {
      for (int i = 0; i <= 500000; i++) 
      {
         dp[kth&1][i] = dp[!(kth&1)][i];
         // iterator por todas as possibilidades de usar pesos repetidos de cada set
         for (int j = 1; j <= it->second; j++) 
         {
            if (i -  j * it->first < 0) 
               break;
            dp[kth&1][i] += dp[!(kth&1)][i-j*it->first];
         }
      }
   }
   // somando o numero de formas de formar uma sacola com peso primo
   for (int j = 0; j <= 500000; j++) 
   {
      if (prime[j]) 
         res += dp[!(kth&1)][j];
   }
   return res;
}

int main()
{
   ios::sync_with_stdio(0);
   int n;
   cin >> n;
   vector<int> nums(n);
   for(int i = 0; i < n; ++i)
      cin >> nums[i];
   cout << getCount(nums) << endl;
   return 0;
}