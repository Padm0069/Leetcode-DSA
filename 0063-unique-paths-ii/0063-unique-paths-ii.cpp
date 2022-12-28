class Solution {
public:
// int mod = (in(ie9+7);

// int mazeObstaclesUtil(int i, int j, vector<vector<int> > &maze, vector<vector<int>> 
// &dp) {
//   if(i>0 && j>0 && maze[i][j]==-1) return 0; 
//   if(i==0 && j == 0)
//     return 1;
//   if(i<0 || j<0)
//     return 0;
//   if(dp[i][j]!=-1) return dp[i][j];
    
//   int up = mazeObstaclesUtil(i-1,j,maze,dp);
//   int left = mazeObstaclesUtil(i,j-1,maze,dp);
  
//   return dp[i][j] = up+left;
  
// }
        
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = 1;  // Because you can only arrive to dp[1][1] from dp[0][1] or dp[1][0], you can only set one of them as 1 so that dp[1][1] can be 1, which means when you at the obstacleGrid[0][0], there are only 1 path.
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
        
    }
};