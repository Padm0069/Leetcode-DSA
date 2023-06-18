class Solution {
private:
    int f(int i, int j, int prev, vector<vector<int>> &grid, vector<vector<int>> &dp){
        //out of boundary and if path is not increasing I can't make a possible path
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || prev>= grid[i][j])
            return 0;

        //if I have answer, use that
        if(dp[i][j] != -1) return dp[i][j];
        
        //explore: go in all 4 direction to check increasing paths
        long long cnt = 1;

        cnt += f(i+1, j, grid[i][j], grid, dp)% mod;
        cnt += f(i-1, j, grid[i][j], grid, dp) % mod;
        cnt += f(i, j+1, grid[i][j], grid, dp) % mod;
        cnt += f(i, j-1,  grid[i][j], grid, dp) % mod;

        return dp[i][j] = cnt;
    }

public:
    int mod = 1e9+7;
    int countPaths(vector<vector<int>>& grid) {
        long long cnt = 0, n= grid.size(), m= grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1)); //dp table

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                cnt += f(i, j, -1, grid, dp);
            }
        }

        return cnt%mod;
    }
};