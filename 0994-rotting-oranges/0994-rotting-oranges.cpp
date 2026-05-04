class Solution {
public:
    int dy[4] = {0,0,-1,1};
    int dx[4] = {-1,1,0,0};
    int num_fresh = 0;

    int m;
    int n;


    bool isValid(int y, int x)
    {
        if(x<0 || x>= n || y<0 || y>=m)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                {
                    num_fresh+=1;
                }
                else if(grid[i][j] == 2)
                {
                    q.push(make_pair(i,j));
                }
            }
        }

        if(num_fresh == 0)
        {
            return 0;
        }

        while(!q.empty())
        {

            int size = q.size();
            for(int i=0;i<size;i++)
            {
                pair<int,int> now = q.front();
                q.pop();
                
                for(int j=0;j<4;j++)
                {
                    int y_n = now.first+dy[j];
                    int x_n = now.second+dx[j];
                    if(((isValid(y_n,x_n)==true)) && (grid[y_n][x_n]==1))
                    {
                        grid[y_n][x_n] = 2;
                        q.push(make_pair(y_n,x_n));
                        num_fresh-=1;

                    }
                }
            }
            ans++;
            
        }

        if(num_fresh != 0)
        {
            return -1;
        }


        return ans-1;
    }
};