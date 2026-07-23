#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    
    int n_id = id_list.size();
    int n_report = report.size();
    
    vector<int> answer(n_id, 0);
    unordered_map<string, int> index;
    vector<unordered_set<int>> reported(n_id);
    vector<int> reportCount(n_id, 0);
    
    
    for(int i=0;i<n_id;i++)
    {
        index[id_list[i]] = i;
    }
    
    for(int i=0;i<n_report;i++)
    {
        int pos = report[i].find(' ');
        
        string from = report[i].substr(0, pos);
        string to = report[i].substr(pos+1);
        
        int reporter = index[from];
        int suspect = index[to];
        
        if (reported[reporter].insert(suspect).second)
        {
            reportCount[suspect]++;
        }
        
    }
    
    
    for(int i=0;i<n_id;i++)
    {
        for(int temp : reported[i])
        {
            if(reportCount[temp] >= k)
            {
                answer[i]++;
            }
        }
    }
    
    
    
    return answer;
}