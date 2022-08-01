class Solution {
public:
    int reverse(int x) {
         int rev = 0;
       while (x){
           int digit = x % 10;
           x /= 10;
           if ((rev > 0 && rev > (INT_MAX - digit)/10) | (rev < 0 && rev < (INT_MIN - digit)/10)) return 0;
           rev = rev * 10 + digit;
       }
       return rev;
        
        
    }
};
// Integer.MAX_VALUE is equal 2147483647. Integer.MIN_VALUE is equal  -2147483648. Last digits are 7 and 8. This is the reason why we check  pop>7 and pop < -8 conditions