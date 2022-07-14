class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    
    uint32_t m = 0;
        
    for (int i = 0; i < 32; i++)
    {
       m <<= 1;
       m |= n & 1;
        n >>= 1;
     }
        
        return m;
    }
};

        
        
// with that in mind lets simplify the loop to 4 bits:

// at the beginning
// m = 0000;
// n = 1010;

// after the first iteration we have
// m = 0000;
// n = 0101;
// n register is shifted to the right by one bit and nothing happens to m;

// second iteration
// m= 0001;
// n =0010;
// n register is shifted to the right by one bit again, this time when m gets a bit because m |= (0101 & 0001)

// third iteration
// m = 0010;
// n = 0001;

// fourth iteration
// m = 0101;
// n = 0000;

// then we return m;
