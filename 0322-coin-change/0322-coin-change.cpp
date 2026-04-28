class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        vector<int> DP(amount + 1, amount + 1);
        DP[0] = 0;

        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<len;j++)
            {
                if(i - coins[j] >= 0)
                DP[i] = min(DP[i-coins[j]]+1, DP[i]);
            }
        }
    return (DP[amount] > amount) ? -1 : DP[amount];

    }
};