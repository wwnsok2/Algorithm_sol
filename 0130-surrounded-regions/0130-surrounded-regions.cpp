class Solution {
public:
    int m, n;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

  
    void DFS(int y, int x, vector<vector<char>>& board)
    {
        board[y][x] = 'S';

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < m && nx >= 0 && nx < n && board[ny][nx] == 'O')
            {
                DFS(ny, nx, board);
            }
        }
    }

    void solve(vector<vector<char>>& board)
    {
        if (board.empty()) return;
        m = board.size();
        n = board[0].size();

      
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O') DFS(i, 0, board);
            if (board[i][n - 1] == 'O') DFS(i, n - 1, board);
        }
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O') DFS(0, j, board);
            if (board[m - 1][j] == 'O') DFS(m - 1, j, board);
        }

      
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O') board[i][j] = 'X'; 
                else if (board[i][j] == 'S') board[i][j] = 'O'; 
            }
        }
    }
};