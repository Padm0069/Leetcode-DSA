class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1);
        int ans = 1;
        
        for(int i=0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    dp[i] = max(dp[i],1+dp[prev]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};