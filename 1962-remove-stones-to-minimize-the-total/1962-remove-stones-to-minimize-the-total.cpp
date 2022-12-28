class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end());
        int ans = 0;
        
        for(int i = 0;i<k;i++){
            int rem = pq.top();
            pq.pop();
            rem-=floor(rem/2);
            pq.push(rem);
        }
        
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};