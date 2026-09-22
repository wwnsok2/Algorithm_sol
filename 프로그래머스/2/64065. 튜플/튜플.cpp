#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> num;
    string temp = "";
    vector<int> temp_num;
    
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))
        {
            temp += s[i];
        }
        else
        {
            if(!temp.empty())
            {
                temp_num.push_back(stoi(temp));
                temp.clear();
            }
            
            if(s[i] == '}' && !temp_num.empty())
            {
                num.push_back(temp_num);
                temp_num.clear();
            }
        }
    }
    
    sort(num.begin(), num.end(), [](const vector<int>& a, const vector<int>& b)
         {return a.size() < b.size();});
    
    for(int i=0;i<num.size();i++)
    {
        for(int j=0;j<num[i].size();j++)
        {
            if(find(answer.begin(), answer.end(), num[i][j]) == answer.end())
            {
                answer.push_back(num[i][j]);
            }
        }
    }
    
    return answer;
}