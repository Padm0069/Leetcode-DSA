class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
       vector<int> ans(intervals.size());
        map<int, int> m;
        for(int i = 0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;     //storing all the start times
        for(int i = 0; i < intervals.size(); i++) 
               ans[i]  = m.lower_bound(intervals[i][1])!=end(m)?m.lower_bound(intervals[i][1]) -> second:-1;        //finding the lower bound for the end time and storing it 
        return ans;
    }
};