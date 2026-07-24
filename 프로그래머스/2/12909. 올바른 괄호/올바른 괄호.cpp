#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    string stack;
    
    int len = s.size();
    
    if(len%2 != 0)
    {
        return false;
    }
    
    if(s[0] == ')')
    {
        return false;
    }
    else if(s[len-1] == '(')
    {
        return false;
    }
    
    for(int i=0;i<len;i++)
    {
        if(s[i] == '(')
        {
            stack += '(';
        }
        else if(s[i] == ')')
        {
            if(!stack.empty())
            {
                stack.pop_back();
            }
            else
            {
                return false;
            }
        }
    }
    
    

    return stack.empty();
}