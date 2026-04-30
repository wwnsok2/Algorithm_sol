#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>


class Solution {
public:
    vector<string> ans;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int m = tickets.size();
        unordered_map<string,vector<string>> map;
        

        for(int i=0;i<tickets.size();i++)
        {
            map[tickets[i][0]].push_back(tickets[i][1]);
        }
        for(auto& pair : map)
        {
            sort(pair.second.begin(), pair.second.end(), greater<string>());
        }
        DFS("JFK",map);
        reverse(ans.begin(), ans.end());

        return ans;
    }

    void DFS(string now, unordered_map<string,vector<string>>& map)
    {
        while (!map[now].empty())
        {
            string next = map[now].back(); 
            map[now].pop_back();
            DFS(next, map);
        }
        ans.push_back(now);
    }
};