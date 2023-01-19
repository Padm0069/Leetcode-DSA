class Solution {
public:
//     The only thing and the most important this is to understand why this line of code works and why it gives the desired outputs.
// if(mp.find(rem)!=mp.end())
// count+=mp[rem];
// We are increasing the count by the number of times the given remainder has been seen.
// I am considering it a fact that :
// If the remainders of array upto i and array upto j are equal (ri=rj),
// then subarray from i to j has a remainder of 0,
// which means It's the type of subarrays we're looking for!
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        
        int i = 0, count = 0;
        int curr_sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;// this is done because initial cumulative sum = 0 and that sum%k will be equal to 0 always
        
        while(i<n)
        {
            curr_sum+= nums[i++];
            int rem = curr_sum % k;
            if(rem<0) rem += k;
            
            if(mp.find(rem)!=mp.end())
                count+=mp[rem];
            
            mp[rem]++;
            
        }
        return count;
    }
};