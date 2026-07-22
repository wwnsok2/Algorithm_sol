class Solution {
public:
    int n;
    int dist = 1;
    int dx[8] = {0,0,-1,1,1,-1,-1,1};
    int dy[8] = {-1,1,0,0,1,-1,1,-1};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0] == 1)
        {
            return -1;
        }
        else if(grid[n-1][n-1] == 1)
        {
            return -1;
        }

        return BFS(grid,0,0);
    }

    int isValid(int y, int x)
    {
        if(x<0 || x>=n || y<0 || y>=n)
        {
            return 0;
        }

        return 1;
    }

    int BFS(vector<vector<int>>& grid, int y, int x)
    {
        grid[0][0] = 1;
        
        queue<pair<int, int>> q;
        q.push(make_pair(y,x));
        

        while(!q.empty())
        {
            int q_size = q.size();
            for(int j=0;j<q_size;j++)
            {
                pair<int,int> now = q.front();
                q.pop();

                if(now.first == n-1 && now.second == n-1)
                {
                    return dist;
                }

                for(int i=0;i<8;i++)
                {
                    int y_n = now.first + dy[i];
                    int x_n = now.second + dx[i];

                    if(isValid(y_n,x_n) && grid[y_n][x_n] == 0)
                    {
                        grid[y_n][x_n] = 1;
                        q.push({y_n, x_n});
                    }
                }
            }
            dist += 1;
        }

        return -1;
    }
};