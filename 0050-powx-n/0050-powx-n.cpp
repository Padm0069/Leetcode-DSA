class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        
        while (nn) {
    if (nn % 2) {
      ans = ans * x;           //4^5 = 4 * 4^4, so we multiply 4 and decrease pow by 1.
      nn = nn - 1;
    } else {
      x = x * x;                //4^4 = (4*4)^2  so multiply x by itself and half the pow.
      nn = nn / 2;
    }
  }
  
        if (n < 0) ans = (double)(1.0) / (double)(ans);
  
        return ans;
    }
};