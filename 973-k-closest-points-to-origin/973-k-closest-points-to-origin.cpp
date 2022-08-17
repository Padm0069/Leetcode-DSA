class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>pq;
        int j=0;
        for(int i=0;i<points.size();i++)
        {
           int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({d,{points[i][0],points[i][1]}});
                       if(pq.size()>k)
                       {
                           pq.pop();
                       }
                
        }
                    vector<vector<int>>res;
                    vector<int>ans;
                    while(pq.empty()==false)
                    {int x=pq.top().second.first; //Taking the coordinates of the points.
                     int y=pq.top().second.second;
                     pq.pop();
                     ans.push_back(x);
                     ans.push_back(y);
                     res.push_back(ans);
                     ans.clear();
                        
                    }
                    return res;
    }
};