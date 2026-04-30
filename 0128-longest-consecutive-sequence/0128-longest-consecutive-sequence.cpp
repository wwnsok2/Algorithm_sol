class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> nums_adj(nums.begin(), nums.end());
        int ans = 0;

        for(auto num : nums_adj)
        {
            
            if(nums_adj.find(num - 1) == nums_adj.end())
            {
                int now = num;
                int temp = 1;
                while(nums_adj.find(now+1) != nums_adj.end())
                {
                    now++;
                    temp++;
                }
                ans = max(ans, temp);
            }

        }
        return ans;
    }
};