#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    
    int num = truck_weights.size();
    queue<int> q;
    
    for(int i=0;i<bridge_length-1;i++)
    {
        q.push(0);
    }
    
    q.push(truck_weights[0]);
    num += -1;
    int total_weight = truck_weights[0];
    
    while(total_weight > 0 || num > 0)
    {
        answer ++;
        
        int out = q.front();
        q.pop();
        
        if(out != 0)
        {
            total_weight = total_weight - out;
        }
        
        if(num > 0 && total_weight + truck_weights[truck_weights.size() - num] <= weight)
        {
            q.push(truck_weights[truck_weights.size() - num]);
            total_weight += truck_weights[truck_weights.size() - num];
            num += -1;
            
        }
        else
        {
            q.push(0);   
        }
        
    }
    
    
    return answer;
}