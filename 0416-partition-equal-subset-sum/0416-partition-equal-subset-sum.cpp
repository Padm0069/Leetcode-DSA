class Solution {
public:
    bool f(int index, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target==0) return true;

        if(index==0) return nums[0] == target;

        if(dp[index][target]!=-1) return dp[index][target];

        bool notTake = f(index-1, target, nums, dp);

        bool take = false;
        if(nums[index]<=target) take = f(index-1, target-nums[index], nums, dp);

        return dp[index][target] = notTake||take;
    }
    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+=nums[i];
        }

        if(sum%2!=0) return false;
        else{
        int k = sum/2;
        vector<vector<int>>dp(n, vector<int>(k+1, -1));

        return f(n-1, k, nums, dp);}
    }
};