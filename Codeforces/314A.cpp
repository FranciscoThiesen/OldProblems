#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int a;
    cin >> a;
    if(a >= 0)
        cout << a << endl;
    else
    {
        string num = to_string(a);
        char c = num[num.size()-1];
        char d = num[num.size()-2];
        bool ceta = true;
        if(a < 0)
        {
            if(a >= -10)
                cout << "0";
            else
            {
                if(c - '0' < d - '0')
                    ceta = false;
                if(num.size() == 3 && num[num.size()-1] == '0')
                    cout << 0;
                else
                {
                    for(int i = 0; i < num.size(); i++)
                    {
                        if(ceta)
                        {
                            if(i != num.size()-1)
                                cout << num[i];
                        }
                        else
                        {
                            if(i != num.size()-2)
                                cout << num[i];
                        }
                    }
                }
            }
        cout << endl;
        }
        
    }
    return 0;
}

