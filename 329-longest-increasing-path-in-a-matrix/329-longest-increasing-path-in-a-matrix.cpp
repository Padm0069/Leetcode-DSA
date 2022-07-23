class Solution {
public:
    
    int DFS(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j, int row, int col) {
    if (dp[i][j] > 0) {
        return dp[i][j];
    }
    int left = 1, right = 1,up = 1,down = 1;
    if (j > 0 && matrix[i][j - 1] > matrix[i][j]) {
        left = 1 + DFS(matrix, dp, i, j-1 ,row, col);
    }
    if (j < (col-1) && matrix[i][j + 1] > matrix[i][j]) {
        right = 1 + DFS(matrix, dp, i, j+1 ,row, col);
    }
    if (i > 0 && matrix[i - 1][j] > matrix[i][j]) {
        up = 1 + DFS(matrix, dp, i-1, j ,row, col);
    }
    if (i < (row-1) && matrix[i + 1][j] > matrix[i][j]) {
        down = 1 + DFS(matrix, dp, i+1, j ,row, col);
    }
    dp[i][j]=max(max(left, right), max(up, down));
    return dp[i][j];
}

    int longestIncreasingPath(vector<vector<int>>& matrix) {
    //init
    int row=matrix.size();
    if (!row) return 0;
    int col=matrix[0].size();
    vector<vector<int>> dp(row, vector<int>(col, 0));
    int maxd = 0, tmp;
    for (int i = 0;i<row;i++) {
        for (int j = 0;j<col;j++) {
            tmp = DFS(matrix, dp  , i, j, row, col);
            maxd=max(maxd, tmp);
        }
    }
    
    return maxd;
}
};