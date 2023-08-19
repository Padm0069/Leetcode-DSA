class Solution {
public:
    int dp[501][501][2];
    
    int getAns(int l, int r, vector <int> &piles, int turn) {
        
        if(l > r) {
            return 0;
        }
        
        if(dp[l][r][turn]!=-1) {
            return dp[l][r][turn];
        }
        
        int res = 0;
        
        if(turn == 0) {
            res = max(piles[l] + getAns(l+1,r,piles,1-turn), piles[r] + getAns(l,r-1,piles,1-turn));
        } else {
            res = min(getAns(l+1,r,piles,1-turn) - piles[l], getAns(l,r-1,piles,1-turn) - piles[r]);
        }
        
        dp[l][r][turn] = res;
        return res;
    }
    
    bool stoneGame(vector<int>& piles) {
        int l = 0;
        int r = piles.size()-1;
        
        memset(dp, -1, sizeof(dp));
        
        // score = score(Alex) - score(Lee)
        int score = getAns(l, r, piles, 0); // 0 -> Alex turn
        
        return score > 0;
    }
};