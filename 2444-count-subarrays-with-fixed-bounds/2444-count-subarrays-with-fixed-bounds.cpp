class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        bool minFound = false,maxFound = false;
        int start = 0,minStart = 0,maxStart = 0;
        
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            if(num < minK || num > maxK){
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            
            if(num == minK){
                minFound  = true;
                minStart = i;
            }
            if(num == maxK){
                maxFound = true;
                maxStart = i;
            }
            
            if(minFound && maxFound){
                res += (min(minStart,maxStart) - start + 1);  //We are adding the total number of subarrays having min start or max start as ending like at minstart = 1 there are 5 subarrays , at minstart = 2 there are 3 subarrays so for calulating that we are doing res += (min(minStart,maxStart) - start + 1);
            }
        }
        return res;
    }
};