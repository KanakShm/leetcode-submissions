class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int res = ~0;
        for (int i = left; i <= right; ++i) {
            res &= i;
        }

        return res;
    }
};