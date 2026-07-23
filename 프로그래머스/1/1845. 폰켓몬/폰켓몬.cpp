#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    vector<int> v;
    int n = nums.size();
    
    for(int i=0;i<n;i++)
    {
        if(find(v.begin(), v.end(), nums[i]) == v.end() && v.size() < n/2)
        {
            v.push_back(nums[i]);
        }
    }
    
    answer = v.size();
    
    return answer;
}