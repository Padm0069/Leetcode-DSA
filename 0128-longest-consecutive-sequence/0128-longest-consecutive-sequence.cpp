class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans = 0;
 
        //inserting all the array elements in Set.
        for (int i = 0; i < nums.size(); i++)
           s.insert(nums[i]);
 
        //checking each possible sequence from the start.
        for(auto x: s)
{
// if nums[i] - 1 is not found it means that it is
// the starting element of a streak
if(s.find(x-1)==s.end())
{
int end = x;
while(s.find(end)!=s.end())
end++;
ans = max(ans,end-x);
}
}
return ans;
    }
};