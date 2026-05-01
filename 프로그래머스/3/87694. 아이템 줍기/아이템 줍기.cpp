#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int isValid(int y, int x)
{
    if(x<0||x>=101||y<0||y>=101)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int BFS(int y, int x, int target_y, int target_x, queue<pair<int,int>> q, vector<vector<int>>& map, vector<vector<int>>& check)
{
    int cnt = 0;
    q.push(make_pair(y,x));
    check[y][x] = 1;
    
    while(!q.empty())
    {   
        int size = q.size();
        for(int j=0;j<size;j++)
        {
            pair<int,int> now = q.front();
            q.pop();
            if(now.first==target_y && now.second==target_x)
            {
                return cnt;
            }
            
            for(int i=0;i<4;i++)
            {
                int y_n = now.first+dy[i];
                int x_n = now.second+dx[i];
                if((isValid(y_n,x_n) && (check[y_n][x_n] == 0) && (map[y_n][x_n] == 1)))
                {
                    q.push(make_pair(y_n,x_n));
                    check[y_n][x_n] = 1;
                }
            }
        }
        cnt++;
    }
    
    return cnt++;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>> map(101, vector<int>(101,0));
    vector<vector<int>> check(101, vector<int>(101,0));
    queue<pair<int,int>> q;
    vector<vector<int>> adj = rectangle;
    
    for(auto& row : adj)
    {
        for(int& col : row)
        {
            col *= 2;
        }
    }
    
    for(auto rect : adj)
    {
        for(int x_pos=rect[0];x_pos<=rect[2];x_pos++)
        {
            for(int y_pos=rect[1];y_pos<=rect[3];y_pos++)
            {
                map [y_pos][x_pos] = 1;
            }
        }
    }
    for(auto rect : adj)
    {
        for(int x_pos=rect[0]+1;x_pos<=rect[2]-1;x_pos++)
        {
            for(int y_pos=rect[1]+1;y_pos<=rect[3]-1;y_pos++)
            {
                map [y_pos][x_pos] = 0;
            }
        }
    }
    
    answer = BFS(characterY*2, characterX*2, itemY*2, itemX*2, q, map, check)/2;
    
    return answer;
}