#define ll long long

class Solution {
public:
    // evens  = 0, 2, 4, 6, 8  => 5 evens
    // primes = 2, 3, 5, 7     => 4 primes
  
    int p = 1e9 + 7;
    
    // calculating x^y efficeiently
    ll power(long long x, long long y) {
      long long res = 1;    

      x = x % p; // Update x if it is more than or equal to p
      if (x == 0) return 0; 

      while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1) res = (res*x) % p;
        
        // we have did the odd step is it was odd, now do the even step
        y = y>>1; // dividing y by 2, y>>1 is same as y/2
        x = (x*x) % p;
      }
      return res;
    }
  
    int countGoodNumbers(long long n) {
      ll count_of_4s = n/2;
      ll count_of_5s = n - count_of_4s;
      ll ans = ((power(4LL, count_of_4s) % p  * power(5LL, count_of_5s) % p) % p);
      return (int)ans;
    }
};


// Now, we know we have 4 primes = {2, 3, 5, 7} and 5 evens = {0, 2, 4, 6, 8}

// if index == 0
// then there can be any of one evens at even position, so 5 ways
// ans = 5

// if index == 1
// then there was 1 even at index = 0, and at this odd index there can be one of 4 primes
// ans = 5* 4(this pos)

// if index == 2
// then at this even index there can be one of 5 evens
// ans = (5*4) * 5(this pos)

// so, continuing the pattern we can see, it's like, 5*4*5*4*5*4*5..... ans so on
// here no. of 4s = no. of odd positions = n/2
// no. of 5s = no. of even positions = (n-n/2)

// ans = pow(4,count4) * pow(5,count5)