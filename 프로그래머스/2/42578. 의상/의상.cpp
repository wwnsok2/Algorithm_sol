#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int total = clothes.size();
    unordered_map<string, int> m;
    
    for(int i=0;i<total;i++)
    {
        m[clothes[i][1]]++;
    }
    
    for(const auto& p : m)
    {
        m[p.first]++;
    }
    
    int combination = 1;
    
    for(const auto& p : m)
    {
        combination = combination * p.second;
    }
    
    answer = combination - 1;
    
    return answer;
}