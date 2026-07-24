#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    int len = s.size();
    
    vector<int> v;
    string temp = "";
    
    for(int i=0;i<len;i++)
    {
        if(s[i] != ' ')
        {
            temp += s[i];
        }
        else
        {
            v.push_back(stoi(temp));
            temp = "";
        }
    }
    v.push_back(stoi(temp));
    
    sort(v.begin(), v.end());
    
    answer += to_string(v[0]);
    answer += ' ';
    answer += to_string(v[v.size() - 1]);
    
    
    return answer;
}