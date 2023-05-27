class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for (int t=0; t<=amount; t++) {
            if (t % coins[0] == 0) dp[0][t] = 1;
        }
        for (int ind=1; ind<n; ind++) {
            for (int target=0; target<=amount; target++) {
                int notTake = dp[ind-1][target];
                int take = 0;
                if (target >= coins[ind]) take = dp[ind][target-coins[ind]];
                dp[ind][target] = notTake + take;
            }
        }
        return dp[n-1][amount];
    }
};