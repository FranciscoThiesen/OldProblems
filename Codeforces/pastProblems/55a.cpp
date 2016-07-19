#include <cstring> 
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int up = 0;
    int low = 0;
    string s;
    cin >> s;
    for(auto& p : s)
    {
        if(p >= 'A' && p <= 'Z')
            up++;
        else
            low++;
    }
    if(up > low)
    {
        for(auto& p : s)
            if(p >= 'a' && p <= 'z')
                p -= 32;
    }
    else
    {
        for(auto& p : s)
            if(p >= 'A' && p <= 'Z')
                p+=32;
    }
    cout << s << endl;
    return 0; 
}
