class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        
        map<int,int>mp;
        
        for(auto &card:hand){
            mp[card]++;
        }
        
         while (mp.size()!= 0) {
            int cur = mp.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (mp[cur+i] == 0)
                    return false;   
                else if (--mp[cur+i] < 1)
                    mp.erase(cur+i);
            }
        }
        return true;
    }
};