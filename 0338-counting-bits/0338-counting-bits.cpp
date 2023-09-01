class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        
        for(int i = 0;i<=n;i++){
            int digit = 0;
            int num = i;
            while(num){
                num&= (num-1);
                digit++;
            }
            
            ans.push_back(digit);
        }
        
        return ans;
    }
};