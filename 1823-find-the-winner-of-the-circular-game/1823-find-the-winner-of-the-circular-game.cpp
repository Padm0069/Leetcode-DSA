class Solution {
public:
    int helper(int n,int k){
        int ans = 0;
        for(int i=1; i<=n; i++){
            ans = (ans + k) % i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return helper(n,k)+1;   //+1 is for conterting 0-based indexing to 1-based indexing
    }
};

// https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/1601186/C%2B%2B-oror-3-Approach-oror-Easy-Understanding
