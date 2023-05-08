class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        //base case when threr are no intervals
        if(intervals.size()==0)return result;
        //sort takes O(nlogn) time
        sort(intervals.begin(),intervals.end());
        //insert the the the first interval in the result
        result.push_back(intervals[0]);
        int j=0;
        //Traverse the whole vector .Takes O(n) time
        for(int i=1;i<intervals.size();i++)
        {
            //if intevals are overlapping
            if(result[j][1]>=intervals[i][0]) result[j][1]=max(result[j][1],intervals[i][1]);
            //else they are not overlapping
            else
            {
                j++;
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};