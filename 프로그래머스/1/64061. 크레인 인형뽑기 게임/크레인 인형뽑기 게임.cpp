#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    int m = board.size();
    int n = board[0].size();
    int k = moves.size();
    int temp = -1;
    vector<queue<int>> q(n);
    vector<int> select;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if (board[j][i] != 0)
            {
                q[i].push(board[j][i]);
            }
        }
    }
    
    for(int i=0;i<k;i++)
    {
        int idx = moves[i] - 1;
        
        if(q[idx].empty())
        {
            continue;
        }
        
        if(!select.empty() && q[idx].front() == select.back())
        {
            select.pop_back();
            answer += 2;
        }
        else
        {
            select.push_back(q[idx].front());
        }
        
        q[idx].pop();
    }
    
    
    
    
    
    return answer;
}