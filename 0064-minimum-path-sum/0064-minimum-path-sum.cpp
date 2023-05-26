class Solution {
public:
    // int sum(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     int up = 0;
    //     int left = 0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(i==0&&j==0)
    //                 dp[i][j] = grid[0][0];
    //             else
    //                 if(i>0) up = grid[i][j] + dp[i-1][j];
    //                 if(j>0) left = grid[i][j] + dp[i][j-1];
    //                 dp[i][j] = min(up,left);
    //         }
    //     }
    //     return dp[n-1][m-1];
    // }
    int minPathSum(vector<vector<int>>& grid) {
    
    int  m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = grid[0][0];
                }
                else {
                    int up = grid[i][j];
                    int left = grid[i][j];
                    if(i>0) up +=dp[i-1][j];
                    else up +=1e9;
                    if(j>0) left +=dp[i][j-1];
                    else left +=1e9;

                    dp[i][j] = min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};