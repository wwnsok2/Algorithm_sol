#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    pair<int,int> now;
    
    int size = priorities.size();
    queue<pair<int,int>> q;
    
    for(int i=0;i<size;i++)
    {
        q.push({priorities[i],i});
    }
    
    while(!q.empty())
    {
        int flag = 0;
        now  = q.front();
        q.pop();
        int q_size = q.size();
        for(int i=0;i<q_size;i++)
        {
            pair<int,int> temp = q.front();
            q.pop();
            if(temp.first > now.first)
            {
                flag = 1;
            }
            q.push(temp);
        }
        
        if(flag == 1)
        {
            q.push(now);
        }
        else
        {
            answer++;
            if(now.second == location)
            {
                return answer;
            }
        }
        
    }
    
    return -1;
}