class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // https://leetcode.com/problems/minimum-cost-for-tickets/discuss/630868/explanation-from-someone-who-took-2-hours-to-solve
        
        unordered_set<int> day(days.begin(),days.end());
        vector<int> dp(367);
        
        for(int i=1 ; i<366 ; i++)
        {
            dp[i] = dp[i-1];
            if(day.find(i) != day.end())
            {
			// cost of ith day , decision of ith day will be
                dp[i] = min({ dp[i - 1] + costs[0],   // 1st case
                             dp[max(0, i - 7)] + costs[1],  // 2nd case
                             dp[max(0, i - 30)] + costs[2]});  // 3rd case
            }
        }
        return dp[365];
    }
};