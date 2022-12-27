class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>rem;
        for(int i =0;i<rocks.size();i++){
            rem.push_back(capacity[i]-rocks[i]);
        }
        sort(rem.begin(),rem.end());
        
        int count = 0;
        for(auto &k:rem){
            if(k==0) count++;
            
            else if(additionalRocks-k>=0){  //it became zero after taking additonal rocks
                count++;
                additionalRocks-=k;
                
            }
        }
        return count;
    }
};