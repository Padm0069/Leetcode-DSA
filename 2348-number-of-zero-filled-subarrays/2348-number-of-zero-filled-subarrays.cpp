class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long count = 0;
        for(auto i:nums){
            if(i){
              ans += (count*(count+1))/2;
              count = 0;
            }else count++;
        }
        ans+= (count*(count+1))/2;
        return ans;
    }
};