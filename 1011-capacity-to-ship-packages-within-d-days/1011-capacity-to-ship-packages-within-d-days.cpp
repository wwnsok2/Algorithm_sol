class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int ans = 0;
        for(int i=0;i<weights.size();i++)
        {
            sum += weights[i];
        }
        
        int left = *max_element(weights.begin(), weights.end());
        int right = sum;

        while(left <= right)
        {
            long long mid = left + (right - left)/2;
            if(isPossible(mid, weights, days))
            {
                ans = mid;
                right = mid-1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }

    int isPossible(int mid, vector<int>& weights, int days)
    {
        int total = 0;
        int cnt_days = 1;
        for(int i=0;i<weights.size();i++)
        {
            if(total + weights[i] > mid)
            {
                total = 0;
                cnt_days++;
            }
            if(total < mid)
            {
                total += weights[i];
            }
        }
        if(cnt_days <= days)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};