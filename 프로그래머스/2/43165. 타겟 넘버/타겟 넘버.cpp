#include <string>
#include <vector>

using namespace std;

void DFS(int now, vector<int>& numbers, int target, int sum, int& answer)
{
    if(now == numbers.size())
    {
        if(sum == target)
        {
            answer++;          
        }
        return;
    }
    
    DFS(now+1, numbers, target, sum + numbers[now], answer);
    DFS(now+1, numbers, target, sum - numbers[now], answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    DFS(0, numbers, target, 0, answer);
    
    return answer;
}

