// https://www.codechef.com/JUNE16/problems/CHCOINSG
#include <cstdio>
#include <iostream>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        if(x%6 == 0)
            cout << "Misha" << endl;
        else
            cout << "Chef" << endl;
    }
    return 0;
}