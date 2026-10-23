#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int BFS(vector<vector<int>> temp, int start, int n)
{
    vector<bool> visit(n+1,false);
    queue<int> q;
    int cnt = 0;
    
    q.push(start);
    visit[start] = true;
    
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        cnt++;
        
        for(int next : temp[now])
        {
            if(visit[next] == false)
            {
                visit[next] = true;
                q.push(next);
            }
        }
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    int w_size = wires.size();
    
    vector<vector<int>> list(n+1);
    vector<int> visit(n+1,0);
    
    for(int i=0;i<w_size;i++)
    {
        list[wires[i][0]].push_back(wires[i][1]);
        list[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<list[i].size();j++)
        {
            vector<vector<int>> temp = list;
            temp[i].erase(temp[i].begin() + j);
            int cnt_a = BFS(temp, i, n);
            int cnt_b = n - cnt_a;
            int diff = abs(cnt_b - cnt_a);
            
            if(diff <= answer)
            {
                answer = diff;
            }
        }
    }
    
    return answer;
}

