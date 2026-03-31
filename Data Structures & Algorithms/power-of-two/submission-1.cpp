class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n >> i) & 1) {
                count++;
            }
        }

        if (n < 0) count--;
        if (count == 1) return true;
        return false;
    }
};