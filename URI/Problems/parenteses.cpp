#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <cstring>
#include <functional>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int op = 0;
        bool ok = true;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ')')
                op--;
            if(s[i] == ')')
                op++;
            if(op<0)
                break;
        }
        if(op != 0)
            cout << "incorrect" << endl;
        else
            cout << "correct" << endl;
    }
    return 0;
}
