#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int s1 = queue1.size();
    int s2 = queue2.size();
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    long long target = (sum1 + sum2) / 2;
    if ((sum1 + sum2) % 2 != 0)
    {
        return -1;
    }
    
    vector<int> q = queue1;
    q.insert(q.end(), queue2.begin(), queue2.end());
    q.insert(q.end(), q.begin(), q.end());
    
    int start = 0;
    int end = s1-1;
    
    while(!((start==s1+s2-1) && (end==q.size()-1)))
    {
        if(sum1 == target) 
        {
            return answer;
        }
        
        if(sum1 > target)
        {
            sum1 -= q[start];
            start++;
        }
        else if(sum1 < target)
        {
            sum1 += q[end+1];
            end ++;
            if (end >= q.size()) break;
        }
        
        answer ++;
    }
    
    
    
    return -1;
}