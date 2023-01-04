class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, ans = INT_MIN, zeroCounter = 0;
        
        for(int end = 0;end<nums.size();end++){
            if(nums[end] == 0){    //counting the no of zeroes in the window.
                zeroCounter++;
            }
            
            while(zeroCounter>k){       //condition violated i,e no of zeroes>k in the window
                if(nums[start] == 0){
                    zeroCounter--;
                }
                start++;    //contract our window from the start, also if it has zero dec zero counter.
            }
            
            ans = max(ans,end-start+1);
        }
        return ans;
    }
};