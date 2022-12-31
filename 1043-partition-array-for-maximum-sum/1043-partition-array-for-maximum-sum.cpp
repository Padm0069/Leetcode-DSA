class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,-1);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int sum = INT_MIN;
            int max_ele = INT_MIN;
            for(int j = i;j<n && j<i+k;j++){
                max_ele = max(max_ele,arr[j]);
                int cand = j+1 < n ? dp[j+1] + max_ele*(j-i+1) : max_ele*(j-i+1); 
                sum = max(sum , cand);
            }
            dp[i] = sum;
        }
        return dp[0];
    }
};