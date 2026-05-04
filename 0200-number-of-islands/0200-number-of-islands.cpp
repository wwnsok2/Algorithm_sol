class Solution {
public:
    int dy[4] = {0,0,1,-1};
    int dx[4] = {-1,1,0,0};
    int m;
    int n;
    int ans;


    bool isValid(int y,int x)
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

    void DFS(int y, int x, vector<vector<char>>& grid)
    {
        grid[y][x] = '0';

        for(int i=0;i<4;i++)
        {
            int y_n = y+dy[i];
            int x_n = x+dx[i];
            if(isValid(y_n,x_n) && grid[y_n][x_n]=='1')
            {
                grid[y_n][x_n] = '0';
                DFS(y_n,x_n,grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        ans = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1')
                {
                    DFS(i,j,grid);
                    ans++;
                }
            }
        }

        return ans;
    }
};