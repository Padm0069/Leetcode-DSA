class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        int i,j,n=nums.size(),x,y;
        for(i = 0; i < n; i++){
            while(nums[i]){
                x = (nums[i]%10);
                nums[i] = nums[i]/10;
            }
            for(j = i+1; j < n; j++){
                y = nums[j]%10;
                if(__gcd(x,y)==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};