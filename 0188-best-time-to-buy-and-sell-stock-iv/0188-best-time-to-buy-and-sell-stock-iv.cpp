class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        k = 2*k;// transactions for eg k=2, buy-sell(0, 1) buy-sell(2,3)
        // vv<vv<vv<int>>> dp(n+1, vv<vv<int>>(2, vv<int>(k+1, 0)));
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        // index, cap
        for(int i=n-1; i>=0; --i){
                for(int cap=k-1; cap>=0; --cap){
                    int buy = cap%2==0;// determine buy/sell with transaction number
                    int p = 0;
                    if(buy){
                        p = max(-prices[i] + dp[i+1][cap+1], dp[i+1][cap]);
                    }else{
                        p = max(prices[i] + dp[i+1][cap+1], dp[i+1][cap]);
                    }
                    dp[i][cap] = p;
                }
        }
        
        return dp[0][0];
    }
};