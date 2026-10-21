#include <string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    int n = s.size();
    queue<char> q;
    
    if(s[0] == ')' || s[n-1] == '(')
    {
        return false;
    }
    
    for(int i=0;i<n;i++)
    {
        if(s[i] == '(')
        {
            q.push(s[i]);
        }
        else if(s[i] == ')')
        {
            if(q.empty())
            {
                return false;
            }
            q.pop();
        }
    }
    
    if(!q.empty())
    {
        return false;
    }
    
    return true;
}