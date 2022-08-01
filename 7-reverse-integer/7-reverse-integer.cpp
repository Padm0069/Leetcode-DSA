class Solution {
public:
    int reverse(int x) {
         int ans = 0;
        while (x) {
            // overflow check
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
            // get the digit from input number starting at the end
            int digit = x % 10;
            // remove the digit "room" from input number
            x /= 10;
            // add the digit to resultant number
            ans = ans * 10 + digit;
        }
        return ans;
        
        
    }
};
