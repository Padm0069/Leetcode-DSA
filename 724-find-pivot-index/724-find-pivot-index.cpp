class Solution {
public:
    
   
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) sum += num;
        
        int prefixSum = 0; // prefix sum to the left of index i
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(prefixSum * 2 == sum - nums[i]) return i;
            prefixSum += nums[i];
        }
        
        return -1;
    }
};