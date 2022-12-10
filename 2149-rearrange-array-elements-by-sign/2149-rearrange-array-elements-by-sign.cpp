class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int>ans(n,0);
        int posind = 0;
        int negind = 1;
        
        for(auto num:nums){
            if(num>0){
                ans[posind] = num;
                posind+=2;
            }
            
            if(num<0){
                ans[negind] = num;
                negind+=2;
            }
        }
        return ans;
    }
};