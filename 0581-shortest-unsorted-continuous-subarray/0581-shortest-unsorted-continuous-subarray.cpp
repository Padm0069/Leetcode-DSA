/**
 *            /------------\
 * nums:  [2, 6, 4, 8, 10, 9, 15]
 * minr:   2  4  4  8   9  9  15
 *         <--------------------
 * maxl:   2  6  6  8  10 10  15
 *         -------------------->
 */
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxlhs(n);   // max number from left to cur
        vector<int> minrhs(n);   // min number from right to cur
        for (int i = n - 1, minr = INT_MAX; i >= 0; i--) minrhs[i] = minr = min(minr, nums[i]);
        for (int i = 0,     maxl = INT_MIN; i < n;  i++) maxlhs[i] = maxl = max(maxl, nums[i]);

        int i = 0, j = n - 1;
        while (i < n && nums[i] <= minrhs[i]) i++;
        while (j > i && nums[j] >= maxlhs[j]) j--;

        return j + 1 - i;
    }
};

// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/discuss/103062/C%2B%2B-Clean-Code-2-Solution-Sort-O(NlgN)-and-max-min-vectors-O(N)