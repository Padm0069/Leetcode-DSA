class Solution {
public:
    int count_bits(int num){
        int count=0;
        while(num){
            count++;
            num&=(num-1);
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
        int ans=0;
        
        for(int i=0;i<nums.size();++i){
            int count=count_bits(i);
            if(count==k){
                ans+=nums[i];
            }
        }
        return ans;
        
    }
};