#include <string>
using namespace std;

int U[2] = {1,0};
int D[2] = {-1,0};
int R[2] = {0,1};
int L[2] = {0,-1};


int isValid(int y, int x)
{
    if(y<0 || y>10 || x<0 || x>10)
    {
        return 0;
    }
    return 1;
}

int solution(string dirs) {
    int answer = 0;
    int y = 5;
    int x = 5;
    int n = dirs.size();
    
    bool check[11][11][11][11] = {false};
    
    for(int i=0;i<n;i++)
    {
        int y_n;
        int x_n;
        if(dirs[i] == 'U')
        {
            y_n = y + U[0];
            x_n = x + U[1];
        }
        if(dirs[i] == 'D')
        {
            y_n = y + D[0];
            x_n = x + D[1];
        }
        if(dirs[i] == 'R')
        {
            y_n = y + R[0];
            x_n = x + R[1];
        }
        if(dirs[i] == 'L')
        {
            y_n = y + L[0];
            x_n = x + L[1];
        }
        
        if(isValid(y_n, x_n) == 0)
        {
            y_n = y;
            x_n = x;
            continue;
        }
        
        if(check[y][x][y_n][x_n] == false)
        {
            check[y][x][y_n][x_n] = true;
            check[y_n][x_n][y][x] = true;
            answer++;
        }
        
        y = y_n;
        x = x_n;
    }
    
    
    return answer;
}