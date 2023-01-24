class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // insert the n1 vector into the map
        map<int,int> mp;
        for( auto it : nums1 ) mp[it]++;
        
        // if the min common value from n2 is present in the map
        for( auto it : nums2 ){
            if( mp.find(it) != mp.end() ) return it;
        }
        
        return -1;
    }
};