class Solution {
public:
    
    //DP wont work here tho it looks like dp coz
//     The answer is: because of the way we are traversing the maze when doing the dp algorithm. If the path to the answer is complex enough, you won't calculate the cells on right order. Check the following input.

// [
// [0,1,0,0,0],
// [0,1,0,1,0],
// [0,1,0,1,0],
// [0,1,0,1,0],
// [0,0,0,1,0]
// ]
//in one line it is: [[0,1,0,0,0],[0,1,0,1,0],[0,1,0,1,0],[0,1,0,1,0],[0,0,0,1,0]]
// In your dp algorithm, by the time you are calculating, for example, cell (1,2), you still have't calculated the value for cell (2,2). For dp to work there, you would have to write a code that does that path instead of the usual row in range(len(dp)) col in range(len(dp[row])).
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = 1;
int row = grid.size();
if (row == 0) return -1;
int col = grid[0].size();
if (col == 0 ) return -1;
if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;

    queue<pair<int, int>> queue;
    queue.push(make_pair(0,0));
    vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    grid[0][0] = 1;
    while(!queue.empty()){
        auto curr = queue.front();
        int x = curr.first, y = curr.second;
        if( x == row -1 && y == col -1) return grid[x][y];
        
        for(auto direction : directions){
            int nx = x + direction[0];
            int ny = y + direction[1];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0){
                queue.push(make_pair(nx,ny));
                grid[nx][ny] = grid[x][y] + 1;
            }
        }
        queue.pop();
    }
    return -1;
    }
};