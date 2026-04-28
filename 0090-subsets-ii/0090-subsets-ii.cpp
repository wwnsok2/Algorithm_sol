class Solution {
public:
    int len;
    vector<int> temp;
    vector<vector<int>> answer;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        len = nums.size();
        sort(nums.begin(), nums.end());
        

        DFS(0,nums);

        return answer;
    }   

void DFS(int start, vector<int>& nums)
{

        answer.push_back(temp);

        for (int i = start; i < len; i++)
        {
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }

            temp.push_back(nums[i]); 
            DFS(i + 1, nums);         
            temp.pop_back();          
        }
    }
};