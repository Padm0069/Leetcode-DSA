class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //can be used as general code for removing duplicate upto k
        int n = nums.size();
       if (n <= 2) return n;

            int i = 1, j = 1;
            int cnt = 1;
            while (j < n) {
                if (nums[j] != nums[j-1]) {
                    cnt = 1;
                    nums[i++] = nums[j];
                }
                else {
                    if (cnt < 2) {
                        nums[i++] = nums[j];
                        cnt++;
                    }
                }
                ++j;
            }
            return i;
    }
};