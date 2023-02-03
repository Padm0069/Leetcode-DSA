class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Return early if input is empty
        if (nums.empty()) return 0;
		
        int best = INT_MIN;
        // Running products
        int maxProd = 1;
        int minProd = 1;
        
        for (int n: nums) {
            if (n < 0) {
                // Swap max and min
                swap(maxProd, minProd);
                //Lets say nums[i] is a negative number and you want to find maximum product subarray ending at nums[i]. We know that if we multiply nums[i] with max product ending at [i-1], it'll give the least value because the sign is flipped. To get the maximum possible value, obviously we have to multiply nums[i] with min product ending at [i-1]
            }
            // Reset to current value if smaller or larger than it
            // (intuitively means that we start considering a new sub-array)
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            // Update the best
            best = max(best, maxProd);
        }
        
        return best;
    }
};