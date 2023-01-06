class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int high = nums.size()-1;
        int low = 0;
        int mid;
        
        //Boundary cases
        if(high==0)
            return nums[0];
        else if(nums[0]!=nums[1])
            return nums[0];
        else if(nums[high]!=nums[high-1])
            return nums[high];

        while(low<=high)
        {
            mid = low + (high-low)/2;
            //Unique element condition
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];
            
            if(((mid%2)==0 && nums[mid]==nums[mid+1])
               ||  ((mid%2)==1 && nums[mid]==nums[mid-1]))
                low = mid+1;
            else
                high = mid-1;
            
        }
        return -1;
    }
};