class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last = 0, cur = 0;
    
    while(cur < nums.size()) {
        if(nums[cur] != 0) {
            swap(nums[last], nums[cur]);
            last++;
        }
        
        cur++;
    }
        
    }
    
};

// int j = 0;
//         // move all the nonzero elements advance
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] != 0) {
//                 nums[j++] = nums[i];
//             }
//         }
//         for (;j < nums.size(); j++) {
//             nums[j] = 0;
//         }