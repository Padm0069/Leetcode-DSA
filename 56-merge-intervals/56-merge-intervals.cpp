class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeInterval;
        if(intervals.size()==0){
            return mergeInterval;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>temp = intervals[0];
        
        for(auto it:intervals){
            if(it[0]<=temp[1]){
                temp[1] = max(it[1], temp[1]);
            }
            else{
                mergeInterval.push_back(temp);
                temp = it;
            }
        }
        mergeInterval.push_back(temp);
        return mergeInterval; 
    }
};