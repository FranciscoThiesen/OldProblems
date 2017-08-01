#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int gols1 = 0;
        int gols2 = 0;
        int saldo1 = 0;
        int saldo2 = 0;
        int v1 = 0;
        int v2 = 0;
        int adv1 = 0;
        int adv2 = 0;
        int e = 0;
        int a, b;
        char c;
        cin >> a >> c >> b;
        gols1+= a;
        gols2 += b;
        adv2 = b;
        if(a > b)
            v1++;
        else if(b > a)
            v2++;
        else
            e++;

        cin >> b >> c >> a;
        adv1 = a;
        gols1+= a;
        gols2 += b;
        if(a > b)
            v1++;
        else if(b > a)
            v2++;
        else
            e++;
        int p1 = (3*v1) + e;
        int p2 = (3*v2) + e;
        if(p1 > p2)
            cout << "Time 1" << endl;
        else if(p2 > p1)
            cout << "Time 2" << endl;
        else
        {
            if(gols1-gols2 > gols2-gols1)
                cout<< "Time 1" << endl;
            else if(gols2-gols1 > gols1-gols2)
                cout << "Time 2" << endl;
            else
            {
                if(adv1 > adv2)
                    cout << "Time 1" << endl;
                else if(adv2 > adv1)
                    cout << "Time 2" << endl;
                else
                {
                    cout << "Penaltis"<<endl;
                }
            }
        }
    }
    return 0;
}
