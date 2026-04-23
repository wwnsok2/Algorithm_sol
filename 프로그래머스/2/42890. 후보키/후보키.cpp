#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int m = 0;
int n = 0;

bool compare(int a, int b)
{
    return __builtin_popcount(a) < __builtin_popcount(b);
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    
    m = relation.size();
    n = relation[0].size();
    
    vector<int> keys;
    
    vector<int> masks;
    
    for(int i=0;i<(1<<n);i++)
    {
        masks.push_back(i);
    }
    
    sort(masks.begin(), masks.end(), compare);
    
    for(auto &mask : masks)
    {
        bool isMin = true;
        for(auto &key : keys)
        {
            if((key & mask) == key)
            {
                isMin = false;
                break;
            }
        }
        
        if(isMin == false)
        {
            continue;
        }
        
        set<string> s;
        
        for(int i=0;i<m;i++)
        {
            string temp = "";
            
            for(int j=0;j<n;j++)
            {
                if(mask & (1<<j))
                {
                    temp += relation[i][j] + ",";
                }
            }
            s.insert(temp);
        }
        
        if(s.size() == m)
        {
            keys.push_back(mask);    
        }
        
    }
    
    answer = keys.size();
    
    
    return answer;
}