class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
         unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();++i){
            if(mp[nums[i]]==1){
                ans.push_back(nums[i]);
            }
            mp[nums[i]]++;
        }
        
        for(int i=0;i<nums.size();++i){
            if(mp[i+1]==0){
                ans.push_back(i+1);
                break;
            }
        }
        
        return ans;
    }
};