class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = 1;

        int k;

        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        while(start<=end)
        {
            long long cnt = 0;
            int k = start + (end-start)/2;
            for(int i=0;i<n;i++)
            {
                cnt += (piles[i]+k-1)/k; 
            }

            if(cnt<=h)
            {
                ans = k;
                end = k - 1;
            }
            else
            {
                start = k + 1;
            }      
        }

        return ans;

    }
};