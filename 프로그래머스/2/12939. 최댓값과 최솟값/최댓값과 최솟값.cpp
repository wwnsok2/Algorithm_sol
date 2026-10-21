#include <string>
#include <vector>
#include <climits>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = s.size();
    int temp_num = 0;
    string temp = "";
    int min = INT_MAX;
    int max = INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        temp += s[i];
        if(s[i] == ' ' || i == n-1)
        {
            temp_num = stoi(temp);
            if(temp_num >= max)
            {
                max = temp_num;
            }
            if(temp_num <= min)
            {
                min = temp_num;
            }
            
            temp_num = 0;
            temp = "";
        }
    }
    
    answer = to_string(min) + ' ' + to_string(max);
    return answer;
}