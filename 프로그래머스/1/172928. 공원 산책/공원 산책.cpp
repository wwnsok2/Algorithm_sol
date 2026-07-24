#include <string>
#include <vector>

using namespace std;

int w;
int h;
int r_size;

int isValid(int y, int x)
{
    if(y<0 || y>=h || x<0 || x>=w)
    {
        return 0;
    }
    return 1;
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int x;
    int y;
    
    h = park.size();
    w = park[0].size();
    r_size = routes.size();
    
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(park[i][j] == 'S')
            {
                y = i;
                x = j;
                break;
            }
        }
    }
    
    
    
    for(int i=0;i<r_size;i++)
    {
        bool possible = true;
        int x_temp = x;
        int y_temp = y;
        
        int pos = routes[i].find(' ');
        
        string op = routes[i].substr(0,pos);
        string n_str = routes[i].substr(pos+1);
        int n = stoi(n_str);
        
        if(op == "N")
        {
            for(int i=0;i<n;i++)
            {
                y_temp--;
                if(!isValid(y_temp,x) || park[y_temp][x] == 'X')
                {
                    possible = false;
                    break;
                }   
            }
            if (possible)
            {
                y = y_temp;
            }
        }
        else if(op == "S")
        {
            for(int i=0;i<n;i++)
            {
                y_temp++;
                if(!isValid(y_temp,x) || park[y_temp][x] == 'X')
                {
                    possible = false;
                    break;
                }   
            }
            if (possible)
            {
                y = y_temp;
            }
        }
        else if(op == "W")
        {
            for(int i=0;i<n;i++)
            {
                x_temp--;
                if(!isValid(y,x_temp) || park[y][x_temp] == 'X')
                {
                    possible = false;
                    break;
                }   
            }
            if (possible)
            {
                x = x_temp;
            }
        }
        else if(op == "E")
        {
            for(int i=0;i<n;i++)
            {
                x_temp++;
                if(!isValid(y,x_temp) || park[y][x_temp] == 'X')
                {
                    possible = false;
                    break;
                }   
            }
            if (possible)
            {
                x = x_temp;
            }
        }
    }
    
    answer.push_back(y);
    answer.push_back(x);
    
    return answer;
}