class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
    vector<int> dp(n);
    dp[0] = nums[0];
    
    for(int i=1; i<n; i++){
        int incl = nums[i];
        if(i-2 >= 0){
            incl += dp[i-2];
        }
        
        int excl = dp[i-1];
        
        dp[i] = max(incl, excl);
    }
    
    return dp[n-1];
    }
};