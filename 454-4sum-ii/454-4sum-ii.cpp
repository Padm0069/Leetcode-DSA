class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
         int res = 0;
        unordered_map<int, int> AB;
        for (int a : nums1)
            for (int b : nums2)
                AB[a + b]++;
        for (int c : nums3)
            for (int d : nums4)
                res += AB[-c - d];
        return res;
    }
};