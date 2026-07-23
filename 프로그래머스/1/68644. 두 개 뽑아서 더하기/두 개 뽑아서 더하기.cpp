#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int n = numbers.size();
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int temp = numbers[i] + numbers[j];
            if(find(answer.begin(), answer.end(), temp) == answer.end())
            {
                answer.push_back(temp);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}