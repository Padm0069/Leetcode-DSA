class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int num : nums) {
            mpp[num]++;
        }
		//creating min heap that contains pair {freq, value}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it : mpp) {
			//traversing through map
            int val = it.first;
            int freq = it.second;
            pq.push({freq, val});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};