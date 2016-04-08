#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <string>

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }

using namespace std;
bool pyth(int a, int b, int c)
{
    if(a*a + b*b == c*c || b*b + c*c == a*a || a*a + c*c == b*b)
        return true;
    return false;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a;
        cin >> a;
        set<string> nomes;
        string x;
        for(int i = 0; i < a;++i)
        {
            cin >> x;
            nomes.insert(x);
        }
        if(nomes.size() == 1)
            cout << x << endl;
        else
            cout << "ingles" << endl;
    }
    return 0;

}
