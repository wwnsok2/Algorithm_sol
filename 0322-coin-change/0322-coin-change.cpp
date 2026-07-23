class Solution {
public:
    int n;
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<int> dp(amount+1,amount+1);

        if(amount == 0)
        {
            return 0;
        }

        dp[0] = 0;

        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i >= coins[j])
                {
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount] == amount +1)
        {
            return -1;
        }

        return dp[amount];
    }
};