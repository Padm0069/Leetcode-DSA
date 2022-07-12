class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
         int n=triangle.size();
        vector<vector<int>> arr(n,vector<int> (n));
        for(int i=n-1;i>=0;--i)
        {
            for(int j=i;j>=0;--j)
            {
                if(i==n-1)
                {
                    arr[i][j]=triangle[i][j];
                }
                else
                {
                    arr[i][j]=min(arr[i+1][j],arr[i+1][j+1])+triangle[i][j];
                }
            }
        }
        return arr[0][0];
    }
};