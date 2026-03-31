class Solution {
public:
    int hammingWeight(uint32_t n) {
       /*
            start from the right & 1 then bit shift right
       */

        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n >> i) & 1 == 1) {
                count++;
            }
        }
        return count;
    }
};
