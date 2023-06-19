class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int pre[101];
        int ans = 0;
        pre[0] = 0;
        
        for(int i = 1;i<=gain.size();i++){
            pre[i] = pre[i-1]+gain[i-1];
            ans = max(ans,pre[i]);
        }
        
        return ans;
    }
};