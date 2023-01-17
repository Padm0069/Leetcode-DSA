class Solution {
public:
    int minFlipsMonoIncr(string s) {
        //there can be two cases either its a 0 or 1
        int no_one = 0;
        int flips = 0;
        
        for(auto ch:s){
            //if its one no need to flip just inc no of 1 count.
            
            if(ch=='1'){
                no_one++;
            }
            
            //now if its zero either:
            //you can flip 0 to 1 p.e inc flip count.
            //or let it be zero and change all other before 1 to 0 thats why we need no of 1 count.
            
            else{
                flips = min(flips+1,no_one);
            }
        }
        return flips;
    }
};

//dp coz we remembering the no of 1 before 