#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    
    stack<int> s;
    int now = 0;
    int size = prices.size();
    vector<int> answer(size,0);
    
    for(int i=0;i<size;i++)
    {
        if(i==0)
        {
            s.push(i);
            continue;
        }
        
        now = prices[i];
        
        while(!s.empty() && now < prices[s.top()])
        {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        
        s.push(i);
    }
    
    while(!s.empty())
    {
        answer[s.top()] = size - s.top() - 1;
        s.pop();
    }
    
    
    return answer;
}