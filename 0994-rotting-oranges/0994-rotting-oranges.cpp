class Solution {
public:
    int m;
    int n;
    int fresh_num = 0;
    int ans = 0;

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};


    int orangesRotting(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh_num++;
                }
                else if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }
        BFS(q,grid);

        if(fresh_num != 0)
        {
            return -1;
        }

        return ans;
        

    }

    int isValid(int y, int x)
    {
        if(y<0 || y>=m || x<0 || x>=n)
        {
            return 0;
        }

        return 1;
    }

    void BFS(queue<pair<int,int>>& q, vector<vector<int>>& grid)
    {
        while(!q.empty() && fresh_num>0)
        {
            int q_size = q.size();

            for(int i=0;i<q_size;i++)
            {
                pair<int,int> now = q.front();
                q.pop();

                for(int j=0;j<4;j++)
                {
                    int y_n = now.first + dy[j];
                    int x_n = now.second + dx[j];

                    if(isValid(y_n, x_n) && grid[y_n][x_n]==1)
                    {
                        q.push({y_n,x_n});
                        grid[y_n][x_n] = 2;
                        fresh_num--;
                    }
                }
            }

            ans++;

        }
    }
};