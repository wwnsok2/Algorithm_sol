class Solution {
public:
    vector<int> temp;

    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        vector<bool> check(len, false);

        DFS(0, len, nums, check, result);

        return result;

    }

    void DFS(int now, int len, vector<int>& nums, vector<bool>& check, vector<vector<int>>& result)
    {
        if(now == len)
        {
            result.push_back(temp);
        }

        for(int i=0;i<len;i++)
        {
            if(check[i] != true)
            {
                temp.push_back(nums[i]);
                check[i] = true;
                DFS(now+1, len, nums, check, result);
                check[i] = false;
                temp.pop_back();
            }
        }
    }
};