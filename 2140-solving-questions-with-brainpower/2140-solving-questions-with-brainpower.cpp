class Solution {
public:
    long long sumi(int ind, vector<vector<int>>& questions, int n, vector<long long> &dp){
    if(ind==n-1) return questions[n-1][0];
    if(ind>=n) return 0;
    if(dp[ind]!=-1) return dp[ind];
    long long take=questions[ind][0]+sumi(ind+questions[ind][1]+1,questions,n,dp);    
    long long notTake=0+sumi(ind+1,questions,n,dp);
    return dp[ind]=max(take,notTake);
}

    long long mostPoints(vector<vector<int>>& questions) {
        
    int n=questions.size();
     vector<long long> dp(n+1,-1);
     return sumi(0,questions,n,dp);
    }
        
    
};