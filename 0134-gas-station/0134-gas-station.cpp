class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int total = 0;
        int surtotal = 0;
        
        for(int i = 0;i<n;i++){
            total+=gas[i] - cost[i];
            surtotal+= gas[i] - cost[i];
            
            if(surtotal<0){
                surtotal = 0;
                start = i+1;
            }
        }
        
        return total<0?-1:start;
    }
};