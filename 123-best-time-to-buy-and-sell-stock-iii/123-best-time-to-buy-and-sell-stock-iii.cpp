class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        // index, buy, cap
        
        for(int i=n-1; i>=0; --i){
            for(int buy=0; buy<2; ++buy){
                for(int cap=1; cap<3; ++cap){
                    int p = 0;
                    if(buy){
                        p = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]);
                    }else{
                        p = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap] = p;
                }
            }
        }
        return dp[0][1][2];
    }
};