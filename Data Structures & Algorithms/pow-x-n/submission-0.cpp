class Solution {
public:
    double myPow(double x, int n) {
        /*
            if n is odd subtract one make it even
            divide even n by 2 = k
            while (k > 0) multiply x1 by itself x2 by itself
            multiply x1 and x2
            if n was odd multiply x3 by x
        */

        int pos_n = n > 0 ? n : n * -1;
        int pow = pos_n;
        if (pos_n % 2 != 0) {
            pow -= 1;
        }

        int pow_div2 = pow / 2;
        double x1 = 1;
        double x2 = 1;
        while (pow_div2 > 0) {
            x1 *= x;
            x2 *= x;
            pow_div2--;
        }

        double x3 = x1 * x2;
        if (pos_n % 2 != 0) {
            x3 *= x;
        }

        if (n < 0) {
            x3 = 1 / x3;
        }
        return x3;
    }
};
