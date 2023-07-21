class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int start = -1;
        int end = -1;
        int res = 0;
        
        for(int i = 0;i<nums.size();i++){
            //find the range 
            
            if(nums[i]>right){
                start = i;
            }
            
            if(nums[i]>=left){
                end = i;
            }
            
            res+=end-start;
        }
        
        return res;
    }
};