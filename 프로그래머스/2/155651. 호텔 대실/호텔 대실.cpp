#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>

using namespace std;

int convert(string s)
{
    int hour = stoi(s.substr(0,2));
    int minute = stoi(s.substr(3,2));
    
    return hour*60 + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    int p_n = book_time.size();
    priority_queue<int, vector<int>, greater<int>> q;
    sort(book_time.begin(), book_time.end());
    
    q.push(convert(book_time[0][1])+10);
    
    for(int i=1;i<p_n;i++)
    {
        int temp = q.top();
        
        if(convert(book_time[i][0]) < temp)
        {
            answer++;
            q.push(convert(book_time[i][1]) + 10);
        }
        else
        {
            q.pop();
            q.push(convert(book_time[i][1]) + 10);
        }
    }
    
    return answer;
}