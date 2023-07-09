class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int low = 0, high = n-1, mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            //Now we look for which half is sorted in the array 
            if(nums[mid]>=nums[low])
            {
                if(nums[low]<=target  && target <= nums[mid])
                {
                    high = mid-1;
                }
                else 
                    low = mid + 1;
            }
            else
            {
                if(target<=nums[high] && target >= nums[mid])
                {
                    low = mid+1;
                }
                else high = mid-1;
            }
        }
        return -1;
    }
};