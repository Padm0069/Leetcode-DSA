class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // Create a table to store results of subproblems 
	int dp[m + 1][n + 1]; 

	// Fill d[][] in bottom up manner 
	for (int i = 0; i <= m; i++) { 
		for (int j = 0; j <= n; j++) { 
			// If first string is empty, only option is to 
			// insert all characters of second string 
			if (i == 0) 
				dp[i][j] = j; // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of second string 
			else if (j == 0) 
				dp[i][j] = i; // Min. operations = i 

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (word1[i - 1] == word2[j - 1]) 
				dp[i][j] = dp[i - 1][j - 1]; 

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
				dp[i][j] = 1 + min(dp[i][j - 1],  // Insert 
								min(dp[i - 1][j], // Remove 
								dp[i - 1][j - 1])); // Replace 
		} 
	} 

	return dp[m][n]; 
    }
};