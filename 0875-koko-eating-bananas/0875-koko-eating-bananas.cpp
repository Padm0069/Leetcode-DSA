class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;
        
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(canEatInTime(piles, mid, h)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
    
    bool canEatInTime(vector<int>& piles, int k, int h){
        long long hours = 0; //Tracking the hours that will take 
        for(int pile : piles){
            // performing claculation, take an example 
            // k = 4
            // pile = 10

            // pile / k => 10 / 4 = 2
            // pile % k => 2, so we need to have one more hour to eat remaining bananas left over as remainder 
            // hours = 3;
            int div = pile / k;
            hours += div;
            if(pile % k != 0) hours++;  //if remainder is not 0 we need extra hour to finish it
        }
        return hours <= h;
    }
};