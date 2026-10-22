#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int num = 0;
    int temp = -1;
    int s_size = 0;
    stack<int> s;
    vector<int> contain;
    int n = order.size();
    
    for(int i=1;i<n+1;i++)
    {
        if(i == order[num])
        {
            contain.push_back(i);
            num++;
        }
        else
        {
            s.push(i);
        }
          
        while(!s.empty())
        {
            temp = s.top(); 
            
            if(temp == order[num])
            {
                contain.push_back(temp);
                s.pop();
                num++;
            }
            else
            {
                break;
            }
        }
        

    }
    
    answer = contain.size();
    
    return answer;
}