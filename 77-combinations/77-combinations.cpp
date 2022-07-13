class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int> comb;
        backtrack(res,1,n,k,comb);
        return res;
    }
    
    void backtrack(vector<vector<int>>& res, int cur, int n, int k, vector<int>& comb){
        if(k==0){
            res.push_back(comb);
            return;
        }
        // If cur>n-k, there are not enough numbers left, we have to select the current element
        if(cur<=n-k) backtrack(res,cur+1,n,k,comb);  
        comb.push_back(cur);
        backtrack(res,cur+1,n,k-1,comb);

        // Pop to avoid needing to repeatedly copy comb and allow pass by reference
       comb.pop_back();
    }
};