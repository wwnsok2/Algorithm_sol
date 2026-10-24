#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int r_n = road.size();
    vector<vector<int>> time(N+1,vector<int>(N+1,INT_MAX));
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    vector<int> dist(N+1, INT_MAX);
    
    for(int i=0;i<N+1;i++)
    {
        time[i][i] = 0;
    }
        
    for(int i=0;i<r_n;i++)
    {
        if(time[road[i][0]][road[i][1]] > road[i][2])
        {
            time[road[i][0]][road[i][1]] = road[i][2];
            time[road[i][1]][road[i][0]] = road[i][2];
        }
    }
    
    dist[1] = 0;
    q.push({0,1});
    
    while(!q.empty())
    {
        int cost = q.top().first;
        int now = q.top().second;
        q.pop();
        
        if(cost > dist[now])
        {
            continue;
        }
        
        for(int i=1;i<N+1;i++)
        {
            if(time[now][i] == INT_MAX)
            {
                continue;
            }
            
            if(cost + time[now][i] < dist[i])
            {
                dist[i] = cost + time[now][i];
                q.push({dist[i],i});
            }
        }
    }
    
    for(int i=1;i<N+1;i++)
    {
        if(dist[i] <= K)
        {
            answer++;
        }
    }
    
    return answer;
}