class Solution {
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n, string(n, '.'));
        vector<vector<string>> matrix;

        vector<int> check_col(9, 0);
        vector<int> check_diag_add(18, 0);
        vector<int> check_diag_sub(18, 0);

        DFS(0, n, temp, matrix,check_col,check_diag_add,check_diag_sub);

        return matrix;
    }

    void DFS(int y, int n, vector<string>& temp, vector<vector<string>> &matrix, vector<int> &check_col, vector<int> &check_diag_add, vector<int> &check_diag_sub)
    {
        if(y == n)
        {
            matrix.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++)
        {
            if((check_col[i] == 0) && (check_diag_add[y+i] == 0) && (check_diag_sub[y-i+n] == 0))
            {
                temp[y][i] = 'Q';
                check_col[i] = 1;
                check_diag_add[y+i] = 1;
                check_diag_sub[y-i+n] = 1;

                DFS(y+1,n,temp,matrix,check_col,check_diag_add,check_diag_sub);

                temp[y][i] = '.';
                check_col[i] = 0;
                check_diag_add[y+i] = 0;
                check_diag_sub[y-i+n] = 0;
                
            }
        }
    }
};