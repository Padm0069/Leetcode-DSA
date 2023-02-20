class Solution {
public:
    int maxOperations(vector<int>& nums, int k) { 
        unordered_map<int,int>mp;
        int n=nums.size();
        int count=0;

        for(int i=0;i<n;++i){
            int target=k-nums[i];
            if(mp.find(target)!=mp.end()){
                //the sum exists
                count++;
                //if the number exists only once
                if(mp[target]==1){
                    mp.erase(target);
                }
                else{
                    mp[target]--;
                }
            }
            else{
                mp[nums[i]]++;      //add the number to map
            }
        }
        return count;
    }
};