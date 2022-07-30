class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> v(n,0);
        
        for(int i=0;i<n;i++){
            int row=0, col=i;     // current column
            while(1){
                
                // New column in the next row we will transition into. 
                //Here we can leverage the column value itself. 
                //if it is 1 we will move to next column, 
                //if it is -1 we will move to peviouis column
                int newcol = grid[row][col]+col;
                
                // we can only move to next row if there is no v shape in the current row, check current + newcol value for the current row
                // If there is no blockage move to next row
                if(0<=newcol && n>newcol && grid[row][col]==grid[row][newcol]){
                    row++;
                    col=newcol;
                } else{                    
                    // There is a blocakage , break
                    v[i]=-1;
                    break;
                }
                if(row>=m){
                    // we reached out of the last row
                    v[i]=col;
                    break;
                }
            }
        }
        return v;
    }
};