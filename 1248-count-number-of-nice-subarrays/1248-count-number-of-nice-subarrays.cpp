class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int ,int> m;       //for storing the count of prefix sum.
 
        for(int i=0;i<nums.size();++i)   //converting it to binary array, even->0 and odd->1
        {
            if(nums[i]&1)
                nums[i]=1;
 
            else
                nums[i]=0;
        }
 
        int sum=0,i,cnt=0;              
        for(i=0;i<nums.size();++i)          //doing subarray sum equal to k.
        {
            sum+=nums[i];
            if(sum==k)
                cnt++;
 
            if(m.find(sum-k)!=m.end())
                cnt+=m[sum-k];
 
            m[sum]++;
        }
 
        return cnt;
    }
};