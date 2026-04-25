#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dx[4]= {0,0,-1,1};
int dy[4]= {-1,1,0,0};

int isVal(int y, int x, vector<vector<int>>& maps)
{
    if((y<0) || (y>=maps.size()) || (x<0) || (x>=maps[0].size()))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int BFS(int y, int x, vector<vector<int>>& maps)
{
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    
    while(!q.empty())
    {
        pair<int,int> now = q.front();
        
        if((now.first==maps.size()-1) && (now.second==maps[0].size()-1))
        {
            return maps[now.first][now.second];
        }
        
        q.pop();
        
        for(int i=0;i<4;i++)
        {
            int y_n = now.first + dy[i];
            int x_n = now.second + dx[i];
            if((isVal(y_n,x_n,maps) == 1) && (maps[y_n][x_n] == 1))
            {
                q.push(make_pair(y_n,x_n));
                maps[y_n][x_n] = maps[now.first][now.second] + 1;
            }
        }
    }
               
    return -1;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    answer = BFS(0,0,maps);
    
    return answer;
}
