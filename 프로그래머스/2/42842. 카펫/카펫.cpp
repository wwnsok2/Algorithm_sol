#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total = brown + yellow;
    int y = 0;
    int x = 0;
    
    for(y=1;y*y<=total;y++)
    {
        if(total % y == 0)
        {
            int x = total / y;
            int n_yellow = (x-2) * (y-2);
            
            if(n_yellow == yellow)
            {
                answer.push_back(x);
                answer.push_back(y);
                break;
            }
        }
    }
    
    return answer;
}