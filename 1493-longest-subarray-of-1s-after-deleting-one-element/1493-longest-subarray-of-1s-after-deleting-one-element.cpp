class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int zeroes = 0;
        int ans = INT_MIN;
        for(int j =i;j<nums.size();j++){
            if(nums[j] == 0) zeroes++; 
            if(zeroes>=2){
                while(zeroes>=2){     //invalid window
                if(nums[i] == 0){
                    zeroes--;
                }
                i++;
            }
            }
            
            
            ans = max(ans,j-i);
            
        }
        return ans;
    }
};