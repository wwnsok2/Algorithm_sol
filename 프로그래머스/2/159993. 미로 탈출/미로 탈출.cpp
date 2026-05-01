#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int m;
int n;

int lever_x;
int lever_y;

int isValid(int y, int x, int m, int n)
{
    if(y<0 || y>= m || x<0 || x>= n)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int BFS(int y, int x, queue<pair<int,int>> q, vector<string>& maps, char target, vector<vector<int>>& check)
{
    int time = 0;
    q.push(make_pair(y,x));
    
    while(!q.empty())
    {
        int size = q.size();
        for(int j=0;j<size;j++)
        {
            pair<int,int> now = q.front();
            q.pop();
            
            if(maps[now.first][now.second] == target)
            {
                lever_y = now.first;
                lever_x = now.second;
                return time;
            }
            
            for(int i=0;i<4;i++)
            {
                int y_n = now.first+dy[i];
                int x_n = now.second+dx[i];
                if(isValid(y_n,x_n,m,n) && (maps[y_n][x_n] != 'X') && check[y_n][x_n] == 0)
                {
                    check[y_n][x_n] = 1;
                    q.push(make_pair(y_n,x_n));
                }
            }     
        }
        time++;
    }
    
    return -1;
}

int solution(vector<string> maps) {
    m = maps.size();
    n = maps[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> check(m,vector<int>(n,0));
    
    
    int start_y = 0;
    int start_x = 0;
    int flag = 0;
    for(int i=0;i<m;i++)
    {
        if(flag == 1) break;
        for(int j=0;j<n;j++)
        {
            if(maps[i][j] == 'S')
            {
                start_y = i;
                start_x = j;
                flag = 1;
                break;
            }
        }
    }
    
    int time_1 = BFS(start_y, start_x, q, maps, 'L', check);
    if(time_1 == -1)
    {
        return -1;
    }
    check.assign(m,vector<int>(n,0));
    int time_2 = BFS(lever_y, lever_x, q, maps, 'E', check);
    if(time_2 == -1)
    {
        return -1;
    }
    
    
    
    return time_1 + time_2;
}