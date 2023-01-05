class Solution {
public:
   // Helper function to determine number of subarrays with at most k distinct integers
    int helper(vector<int>&nums,int k)
    {
        int i=0,j=0,count=0,n=nums.size();
        unordered_map<int,int>m;
        while(j<n)
        {
            m[nums[j]]++;
            while(i<=j && m.size()>k)
            {
                if(m[nums[i]]==1)
                {
                    m.erase(nums[i]);
                }
                else
                {
                    m[nums[i]]--;
                }
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        // The concept:-->
        // helper(nums,k)=number of subarrays with at most k distinct integers
        // helper(nums,k-1)=number of subarrays with at most k-1 distinct integers
        // So more formally we can say that 
        // helper(nums,k)=number of subarrays with exactly k distinct integers + number of subarrays with less than k distinct integers
        // So if we exclude the number of subarrays with less than k distinct integers from the number of subarrays with at most k distinct integers, we'll get our answer.
        return helper(nums,k)-helper(nums,k-1);
    }
};