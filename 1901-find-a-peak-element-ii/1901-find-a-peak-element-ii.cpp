class Solution {
public:
//     //We will find the maximum for each row (i.e mid) mid=(low + high)/2 using find max function having iteration from i=0 , to last column i.e n-1 .
// The use of finding max in each row , while checking for the every particular value , we have to check in the their left & right adjacent values , as this value at currrent mat[mid][c] is greatest in that particular row .
// Now when mid==0 , we have to only check at mat[mid+1][c] , same for mid==m-1 , only check at mat[mid-1][c] .
    
    int findmax(vector<vector<int>> &mat , int r)  //finding max element in each row 
    {
        int maxe=INT_MIN;
        int idx=0;
        for(int i=0;i<mat[0].size();i++)
        {
            
            if(maxe<mat[r][i])
            {
                maxe=mat[r][i];
                idx=i;
            }
        }
        return idx;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        // Using Binary Search
        int m=mat.size() , n=mat[0].size();
        int l=0 , r=m-1;
        
        while(l<=r)
        {
            int mid=(l+(r-l)/2);
            
            int c=findmax(mat , mid);
            
            int val=mat[mid][c];
            
            if(mid==0)
            {
                if(mat[mid+1][c] < val)
                {
                    return {mid , c};
                }
            }
            else
            if(mid==m-1)
            {
                if(mat[mid-1][c]<val)
                {
                    return {mid , c};
                }
            }
            else
            if(val>mat[mid+1][c] && val>mat[mid-1][c])
            {
                return {mid , c};
            }
            
            
            if( val<mat[mid+1][c]) // This is general binary search 
            {                        // here above condition become false and so value at 
                                     // mat[mid+1][c] is greater so we move downward 
                l=mid+1;
            }
            else
            {                     // else we move upward 
                r=mid-1;
            }
            
            
        }
        
        return {-1 , -1};
        
    }
};