#include <vector>

using namespace std;

vector<vector<int>> rotate(const vector<vector<int>>& key)
{
    int m = key.size();
    vector<vector<int>> temp(m, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            temp[j][m - 1 - i] = key[i][j];
        }
    }
    return temp;
}

bool check(const vector<vector<int>>& new_lock, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (new_lock[i + m - 1][j + m - 1] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    int m = key.size();
    int n = lock.size();
    int new_size = n + (m - 1) * 2;

    for (int r = 0; r < 4; r++)
    {
        for (int x = 0; x <= new_size - m; x++)
        {
            for (int y = 0; y <= new_size - m; y++)
            {
                vector<vector<int>> new_lock(new_size, vector<int>(new_size, 0));
                
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        new_lock[i + m - 1][j + m - 1] = lock[i][j];
                    }
                }

                for (int i = 0; i < m; i++)
                {
                    for (int j = 0; j < m; j++)
                    {
                        new_lock[x + i][y + j] += key[i][j];
                    }
                }

                if (check(new_lock, n, m)) return true;
            }
        }
        key = rotate(key);
    }

    return false;
}