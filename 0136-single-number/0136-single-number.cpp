class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = nums[0];
        int len = nums.size();
        for(int i=1;i<len;i++)
        {
            temp = temp ^ nums[i];
        }

        return temp;
    }
};