class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len = nums.size();
        set<vector<int>> s;
        

        for(int i=0;i<(1<<len);i++)
        {
            vector<int> temp;
            for(int j=0;j<len;j++)
            {
                if(i & (1<<j))
                {
                    temp.push_back(nums[j]);
                    
                }                
            }
            sort(temp.begin(),temp.end());
            s.insert(temp);
        }
        vector<vector<int>> result(s.begin(),s.end());
        return result;
    }
};