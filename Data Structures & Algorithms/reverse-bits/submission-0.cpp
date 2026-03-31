class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t output = 0;
        /*
        0 - 31 (31)
        1 - 29 (30)
        2 - 27 (29)
        */
        for (int i = 0; i < 32; i++) {
            uint32_t val = (n & (1 << i)) >> i;
            output |= val << (31 - i);
        }
        return output;
    }
};
