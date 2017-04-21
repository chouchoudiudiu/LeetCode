class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res= 0;
        for (int i = 0; i < 32; ++i)
            res = (res<<1) + (n>>i &1);
        
        return res;
    }
};



==============================
class Solution {
public:
    uint32_t swapBits(uint32_t x, int i, int j) {
        uint32_t lo = (x >> i) & 1;
        uint32_t hi = (x >> j) & 1;
        if (lo ^ hi)
            x ^= ((1U << i) | (1U << j)); // ..1...1... the bits for exchange are on
        return x;
    }
    uint32_t reverseBits(uint32_t n) {
        uint32_t res= 0;
        for (int i = 0; i < 16; ++i)
            n = swapBits(n, i, 31 - i);
        return n;
    }
};

//call many time? use lookup table to reverse
