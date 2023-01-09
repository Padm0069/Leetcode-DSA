class Solution {
public:
    int candy(vector<int>& ratings) {
        vector <int> res(ratings.size(),1);   //everyone has atleast one candy.
        long long tcandies = 0;               //total candies needed
        
        if(ratings.size()==1)
            return 1;
        
        //now every i can have 2 neighbor i.e i+1 and i-1 so first we come from forward and check for i+1
        
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]> ratings[i-1])         //check for right i.e i+1 neighbor
                res[i]=max(res[i],res[i-1] + 1);             //give 1 if rating high
        }
        tcandies = res[res.size()-1];           //store intermediate answer 
        for(int i=ratings.size()-2;i>=0;i--){      //now come from back and check for left/i-1 neighbor
            if(ratings[i]> ratings[i+1])
                res[i]= max(res[i],res[i+1] + 1);
            
            tcandies+=res[i];                  //store the final result.
        }
        
        return tcandies;
    }
};