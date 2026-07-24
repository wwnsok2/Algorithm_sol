#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int n = progresses.size();
    
    vector<int> day(n,0);
    
    for(int i=0;i<n;i++)
    {
        int temp = 100 - progresses[i];
        int req;
        if(temp%speeds[i] != 0)
        {
            day[i] = temp/speeds[i] + 1;
        }
        else
        {
            day[i] = temp/speeds[i];
        }
    }
    
    queue<int> q;
    
    for(int i=0;i<n;i++)
    {
        q.push(day[i]);
    }
    
    while(!q.empty())
    {
        int cnt = 1;
        int now = q.front();
        q.pop();
        
        
        while(!q.empty() && now >= q.front())
        {
            q.pop();
            cnt++;
        }
        
        answer.push_back(cnt);
    }

    
    return answer;
}