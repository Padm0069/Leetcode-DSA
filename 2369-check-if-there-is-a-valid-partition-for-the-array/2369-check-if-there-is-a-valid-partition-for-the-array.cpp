class Solution {
public:
    bool func(vector<int>&nums,vector<int>&dp,int i){
        int n = nums.size();
        if(i==nums.size()) return true;
        
        if(dp[i]!=-1) return dp[i];
        
        if(i+1<n && nums[i]==nums[i+1]){          //2 equal elements
            if(func(nums,dp,i+2)) return dp[i]=true;
        }
        
        if(i+2<n && nums[i] == nums[i+2] && nums[i] == nums[i+1]){       //3 equal elements
            if(func(nums,dp,i+3)) return dp[i] = true;
        }
        
        if(i+2<n && nums[i]+1 == nums[i+1] && nums[i]+2 == nums[i+2]){      //LCS
            if(func(nums,dp,i+3)) return dp[i] = true; 
        }
        
        return dp[i] = false;
        
    }
    
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return func(nums,dp,0);
    }
};