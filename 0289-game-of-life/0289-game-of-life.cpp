class Solution {
public:
    int dy[8] = {0,0,-1,1,-1,1,-1,1};
    int dx[8] = {1,-1,0,0,-1,1,1,-1};
    int m;
    int n;

    void gameOfLife(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> check = board;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int count = 0;
                for(int k=0;k<8;k++)
                {
                    if(isValid(i+dy[k],j+dx[k]) && (board[i+dy[k]][j+dx[k]] == 1))
                    count++;
                }
                if(count<2 && board[i][j]==1) check[i][j] = 0;
                else if(count==3 && board[i][j]==0) check[i][j]=1;
                else if((count==2 || count==3) && board[i][j]==1) check[i][j] = 1;
                else if(count>3 && board[i][j]==1) check[i][j] = 0;
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                    board[i][j] = check[i][j];
            }
        }

        
    }

    int isValid(int y, int x)
    {
        if(x<0 || x>=n || y<0 || y>=m)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
};