#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int n = scoville.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<n;i++)
    {
        pq.push(scoville[i]);
    }
    
    for(int i=0;i<n-1;i++)
    {
        int check = 1;
        int num_a = pq.top();
        pq.pop();
        int num_b = pq.top();
        pq.pop();
        
        if(num_a < K)
        {
            check = 0;
        }
        
        if(check == 1)
        {
            return i;
        }
        
        int num_new = num_a + num_b*2;
        pq.push(num_new);
    }
    
    if(pq.top() < K)
    {
        return -1;
    }
    else
    {
        return n - 1;
    }
}