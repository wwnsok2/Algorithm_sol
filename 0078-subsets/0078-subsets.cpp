class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        //vector<int> masks;
        vector<vector<int>> result(1 << len);
/*
        for(int i=0;i<(1<<len);i++)
        {
            masks.push_back(i);
        }*/

        for(int i=0;i<(1 << len);i++)
        {
            for(int j=0;j<len;j++)
            {
                if((i & (1 << j)) != 0)
                {
                    result[i].push_back(nums[j]);
                }
            }
            
        }

        return result;
    }
};