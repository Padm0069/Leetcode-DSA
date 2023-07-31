class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //basically number of insertion and deletion
        
        int n = s1.size();
        int m = s2.size();
        int c1 = 0;
        int c2 = 0;
        
        for(char i:s1){
            c1+=i;
        }
        
        for(char j:s2){
            c2+=j;
        }
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = s1[i-1]+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        int lcs = dp[n][m];
        
        return c1-lcs+c2-lcs;
        
    }
};