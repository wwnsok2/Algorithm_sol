class Solution {
public:
    int m;
    int n;

    int dy[4] = {0,0,-1,1};
    int dx[4] = {-1,1,0,0};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int max = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    int temp = DFS(grid, i, j);
                    max = max > temp ? max : temp;
                }
            }
        }

        return max;
    }

        int isValid(int y, int x)
        {
            if(y<0 || y>=m || x<0 || x>=n)
            {
                return 0;
            }
            return 1;
        }

        int DFS(vector<vector<int>>& grid, int y, int x)
        {
            int num = 1;

            grid[y][x] = 0;

            for(int i=0;i<4;i++)
            {
                int y_n = y + dy[i];
                int x_n = x + dx[i];

                if(isValid(y_n,x_n) && grid[y_n][x_n]==1)
                {
                    num += DFS(grid, y_n, x_n);
                }
            }

            return num;
        }

};