#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    queue<int> q;

   
    for(int i=0;i<n;i++)
    {
        int remain = 100 - progresses[i];
       
        if(remain%speeds[i] != 0)
        {
            q.push(remain/speeds[i] + 1);
        }
        else
        {
            q.push(remain/speeds[i]);
        }
    }
    
    int now = q.front();
    int q_size = q.size();
    int cnt = 1;
    q.pop();
    
    for(int i=0;i<q_size;i++)
    {
        int next = q.front();
        if(now < next || q.empty())
        {
            q.pop();
            answer.push_back(cnt);
            cnt = 1;
            now = next;
        }
        else if(now >= next)
        {
            q.pop();
            cnt++;
        }
    }
   
   
    return answer;
}