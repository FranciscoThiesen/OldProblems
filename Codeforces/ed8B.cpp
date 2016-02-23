#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int main()
{
    long long pos = 0;
    string x;
    cin >> x;
    string num;
    for(int i = 0; i < x.size();++i)
    {
        int a;
        num.clear();
        num += x[i];
        long long n = stoi(num);
        if(n%4 == 0)
            pos++;
        for(int j = i+1; j < x.size(); ++j)
        {
            num += x[j];
            int x = (int)num[num.size()-2];
            int y = (int)num[num.size()-1];
            int test = x*10 +y;
            if(test%4 == 0)
                pos++;
        
        }
    }
    cout << pos << endl;
    return 0;
}
