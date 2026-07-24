#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string temp = "";
    
    int len = s.size();
    
    for(int i=0;i<len;i++)
    {
        if(s[i] != ' ')
        {
            temp += s[i];
        }
        else
        {
            for(char& c : temp)
            {
                c = tolower(c);
            }
            
            if(!temp.empty() && islower(temp[0]))
            {
                temp[0] = toupper(temp[0]);
            }
            
            answer += temp;
            answer += ' ';
            temp = "";
        }
            
    }
       
    for(char& c : temp)
    {
        c = tolower(c);
    }
    
    if(!temp.empty() && islower(temp[0]))
    {
        temp[0] = toupper(temp[0]);
    }
            
    answer += temp;
    
    return answer;
}