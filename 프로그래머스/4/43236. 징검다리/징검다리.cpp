#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    if(n==rocks.size())
    {
        return distance;
    }    
    
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int rocks_size = rocks.size();
    int low = 1;
    int high = distance;
    

    
        
    while(low <= high)
    {
        int mid = (low + high)/2;
        int count = 0;
        int now = 0;
        
        for(int i=0;i<rocks_size;i++)
        {
            if(rocks[i] - now < mid)
            {
                count++;
            }
            else
            {
                now = rocks[i];
            }
        }
        
        if(count > n)
        {
            answer = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        
    }
    
    return answer-1;
}