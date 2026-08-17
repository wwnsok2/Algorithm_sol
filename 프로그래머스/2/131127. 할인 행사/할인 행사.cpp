#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int num_want = want.size();
    int num_dis = discount.size();
    map<string,int> m_want;
    
    for(int i=0;i<num_want;i++)
    {
        m_want[want[i]] = number[i];
    }
    
    for(int i=0;i<num_dis-9;i++)
    {
        map<string,int> m_dis;
        for(int j=i;j<i+10;j++)
        {
            m_dis[discount[j]] ++;
        }
        if(m_dis == m_want)
        {
            answer++;
        }
    }
    return answer;
}