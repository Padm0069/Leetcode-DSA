class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
         map<int,int>mp;
        priority_queue<pair<int,int>>pq;
       
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto x:mp)
        {
            pq.push({-x.second,x.first});
        }
        int k=0;
        while(!pq.empty())
        {
            int x=pq.top().first;
            for(int i=0;i<abs(x);i++)
            {
                nums[k++]=pq.top().second;
            }
            pq.pop();
        }
        return nums;
    }
};