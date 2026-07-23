class Solution {
public:
    int m;
    int n;

    int dy[4] = {0,0,-1,1};
    int dx[4] = {-1,1,0,0};

    vector<vector<int>> ans;
    queue<pair<int,int>> q;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        ans.resize(m, vector<int>(n, -1));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({i,j});
                    ans[i][j] = 0;
                }
            }
        }

        BFS();

        return ans;
    }

    int isValid(int y, int x)
    {
        if(y<0 || y>=m || x<0 || x>= n)
        {
            return 0;
        }

        return 1;
    }

    void BFS()
    {
        while(!q.empty())
        {
            int q_size = q.size();
            for(int k=0;k<q_size;k++)
            {
                pair<int, int> now = q.front();
                q.pop();

                for(int i=0;i<4;i++)
                {
                    int y_n = now.first + dy[i];
                    int x_n = now.second + dx[i];

                    if(isValid(y_n,x_n) && ans[y_n][x_n]==-1)
                    {
                        ans[y_n][x_n] = ans[now.first][now.second] + 1;
                        q.push({y_n,x_n});
                    }
                }
            }
            
        }
    }

};