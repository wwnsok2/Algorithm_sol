#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int flag = 0;
    
    int n_skill = skill.size();
    int n_tree = skill_trees.size();
    
    for(int i=0;i<n_tree;i++)
    {
        int flag = 1;
        string temp = "";
        for(auto c : skill_trees[i])
        {
            if(skill.find(c) != string::npos)
            {
                temp += c;
            }
        }
        
        for(int j=0;j<temp.size();j++)
        {
            if(temp[j] != skill[j])
            {
                flag = 0;
                break;
            }
        }
        
        if(flag == 1)
        {
            answer++;
        }
    }
    

    
    return answer;
}