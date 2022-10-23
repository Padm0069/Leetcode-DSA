class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start +(end-start)/2;
            if(nums[mid]==target){
                ans[0] = mid;
                end = mid-1;
            }
            else if(target>nums[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        start = 0;
        end = n-1;
        while(start<=end){
            int mid = start +(end-start)/2;
            if(nums[mid] == target){
                ans[1] = mid;
                start = mid+1;
            }
             else if(target>nums[mid]){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
};