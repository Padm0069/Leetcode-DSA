class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //for non circular array, sum = max_sum(kadane)
        //for circular max_sum = max(sum_circular,sum_noncircular)
        //where sum_circular = total sum - min_sum(nums)
        
        int total = 0, maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for (int& a : nums) {
            curMax = max(curMax + a, a);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + a, a);
            minSum = min(minSum, curMin);
            total += a;
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
        
    }
};

// maxSum>0 is for the cases when all the array elements are negative. Example - [-3,-2,-1]
// Here max sum = -1 ( non circular sum) , min sum = -6, total sum = -6. so the circular sum will be 6-(-6) = 0. Here if we find max(-1,0) , it is 0. But correct answer is -1. Hence we have that check.
// The basic intution is that if circular sum is equal to 0, it means that it did not include any element in max subarray. ( Since min sub array is equal to entire array in this case)