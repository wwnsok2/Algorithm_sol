#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student(n+2,1);
    student[0] = 100;
    student[n+1] = 100;
    
    for(int temp : lost)
    {
        student[temp] -= 1;
    }
    
    for(int temp : reserve)
    {
        student[temp] += 1;
    }
    
    for(int i=1;i<n+1;i++)
    {
        if(student[i] == 2)
        {
            if(student[i-1] == 0)
            {
                student[i] = 1;
                student[i-1] = 1;
            }
            else if(student[i+1] == 0)
            {
                student[i] = 1;
                student[i+1] = 1;
            }
        }
    }
    
    for(int i=1;i<n+1;i++)
    {
        if(student[i] == 1 || student[i] == 2)
        {
            answer += 1;
        }
    }
    
    
    
    return answer;
}