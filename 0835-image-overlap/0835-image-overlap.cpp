class Solution {
public:
    int check(vector<vector<int>> img1, vector<vector<int>> img2, int shift_x, int shift_y) {
        int n = img1.size();
        int num = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i+shift_x >= 0 && i+shift_x < n && j+shift_y >= 0 && j+shift_y < n && img1[i+shift_x][j+shift_y] == 1 && img2[i][j] == 1)
                num++;
            }
        }
        return num;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int out = INT_MIN;
        for(int x=-n;x<n;x++) {
            for(int y=-n;y<n;y++) {
                out = max(out, check(img1, img2, x, y));
            }
        }
        return out;
    }
};