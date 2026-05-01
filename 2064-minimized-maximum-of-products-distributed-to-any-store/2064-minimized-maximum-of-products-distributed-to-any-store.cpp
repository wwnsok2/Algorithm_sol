class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int ans = 0;
        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());

        while(low <= high)
        {
            int mid = (low+high)/2;
            int cnt = 0;

            for(auto stock : quantities)
            {
                if(stock%mid != 0)
                {
                    cnt += (stock/mid + 1);
                }
                else
                {
                    cnt += (stock/mid);
                }
            }

            if(n >= cnt)
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};