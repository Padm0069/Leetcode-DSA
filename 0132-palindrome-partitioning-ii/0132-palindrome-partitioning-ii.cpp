class Solution {
public:
   bool isPalindrome(int i, int j, string& s){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
    
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        for(int i=n-1; i>=0; i--){
            int mini = INT_MAX;
            for(int k = i; k < n; k++){
                if(isPalindrome(i, k, s)){
                    int cost = 1 + dp[k+1];
                    mini = min(mini, cost);
                }

            }
            dp[i] = mini;
        }
        
        return dp[0] - 1;
    }
};