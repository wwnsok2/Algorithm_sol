#include <string>
#include <vector>


using namespace std;
vector<int> check;

void DFS(int now, vector<vector<int>>& computers)
{
    check[now] = 1;
    
    for(int i=0;i<computers[now].size();i++)
    {
        int next = computers[now][i];
        if((next == 1) && (check[i] == 0))
        {
            DFS(i, computers);
        }
    }

}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    check.resize(n,0);
    
    
    for(int i=0;i<n;i++)
    {
        if(check[i] == 0)
        {
            DFS(i,computers); 
            answer++;
        }
        
    }
    
    
    
    return answer;
}