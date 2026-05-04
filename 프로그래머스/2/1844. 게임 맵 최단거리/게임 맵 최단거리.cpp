#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
int m;
int n;
vector<vector<bool>> check;
int ans = 1;

bool isValid(int y, int x)
{
    if(y<0 || y>=m || x<0 || x>=n)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int BFS(int y, int x, queue<pair<int,int>> q, vector<vector<int>>& maps)
{
    check[y][x] = true;
    q.push(make_pair(y,x));
    
    while(!q.empty())
    {
        int size = q.size();
        for(int k=0;k<size;k++)
        {
            pair<int,int> now = q.front();
            q.pop();
            
            if((now.first==m-1) && (now.second==n-1))
            {
                return ans;
            }
            
            for(int i=0;i<4;i++)
            {
                int y_n = now.first + dy[i];
                int x_n = now.second + dx[i];
                
                if(isValid(y_n,x_n) && (check[y_n][x_n]==false) && (maps[y_n][x_n] == 1))
                {
                    q.push(make_pair(y_n,x_n));
                    check[y_n][x_n] = true;
                }
            }            
        }
        ans++;
    }
    
    return -1;
    
}


int solution(vector<vector<int> > maps)
{
    m = maps.size();
    n = maps[0].size();
    check.assign(m,vector<bool>(n,false));
    queue<pair<int,int>> q;
    
    if(maps[m-1][n-1] == 0)
    {
        return -1;
    }
    
    return BFS(0,0,q,maps);
}