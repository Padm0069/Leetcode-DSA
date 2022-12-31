class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
                cuts.insert(cuts.begin(),0);
                cuts.push_back(n);
                sort(cuts.begin(),cuts.end());

                vector<vector<int>> dp(c+3,vector<int> (c+3,0)); // wrong declare with dp[c + 1][c + 1] ⭐
                
                for(int i=c;i>=1;i--){ // i was putting min a 1 ⭐
                    for(int j=1;j<=c;j++){ // i was starting from 1 ⭐
                        if(i > j) continue;
                        long mini = 1e9;
                        for(int ind=i;ind<=j;ind++){
                            long cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                            mini = min(mini,cost);
                        }
                        dp[i][j] = mini;
                    }
                }
                return dp[1][c];
    }
};