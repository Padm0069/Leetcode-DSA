class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int sum = INT_MIN;
            int max_ele = INT_MIN;
            int len = 0;
            for(int j = i;j<n && j<i+k;j++){
                len++;
                max_ele = max(max_ele,arr[j]);
                int cand = max_ele*len + dp[j+1]; 
                sum = max(sum , cand);
            }
            dp[i] = sum;
        }
        return dp[0];
    }
};