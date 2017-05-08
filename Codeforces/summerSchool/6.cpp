#include <set>
#include <algorithm>
#include <stack>
#include <iostream>
#include <cmath>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>
#include <tuple>
#include <map>

using namespace std;

bool solve(string s)
{
	map<char, int> eq;
	eq['('] = 1;
	eq['<'] = 2;
	eq['['] = 3;
	eq['{'] = 4;

	eq[')'] = 5;
	eq['>'] = 6;		
	eq[']'] = 7;
	eq['}'] = 8;

    stack<tuple<int, int, int, int> > pilha;
    map<char, int> cur;
    cur[0] = 0;
    cur[1] = 0;
    cur[2] = 0;
    cur[3] = 0;
    int curSum = 0;
    for(auto& p : s)
    {
        if(p == ')' || p == '>' || p == ']' || p == '}')
        {
        	if(curSum != 0)
        	{
        		pilha.push(make_tuple(cur[0], cur[1], cur[2], cur[3]));
        		cur[0] = 0;
        		cur[1] = 0;
        		cur[2] = 0;
        		cur[3] = 0;
        		curSum = 0;
        	}
        	if(pilha.empty())
        	{
        		return false;
        	}
        	auto t = pilha.top();

        	int count = 0;
        	if(eq[p]%4 == 1)
        		count = get<1>(t);
        	else if(eq[p]%4 == 2)
        		count = get<2>(t);
        	else if(eq[p]%4 == 3)
        		count = get<3>(t);
        	else
        		count = get<0>(t);

        	if(count <= 0)
        		return false;
        	else
        	{
        		if(eq[p]%4 == 1)
	        		get<1>(t)--;
	        	else if(eq[p]%4 == 2)
	        		get<2>(t)--;
	        	else if(eq[p]%4 == 3)
	        		get<3>(t)--;
	        	else
	        		get<0>(t)--;

        		pilha.pop();
        		if(get<0>(t) + get<1>(t) + get<2>(t) + get<3>(t) > 0)
        		{
        			pilha.push(t);
        		}

        	}
        }
        else
        {
        	cur[eq[p]%4]++;
    		curSum++;
    	}
    }
    if(!pilha.empty() || curSum)
    {
    	return false;
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ifstream in;
    in.open("input.txt");
    ofstream out;
	out.open("output.txt");
    in >> n;
    for(int i = 0; i < n; ++i)
    {
    	string k;
    	in >> k;
    	if(solve(k))
    		out << "T" << endl;
    	else
    		out << "NIL" << endl;

    }
    in.close();
    out.close();
    return 0;
}
