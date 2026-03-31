class Solution {
public:
    double myPow(double x, int n) {
        /*
            set power to the positive of n
            while (power is not zero)
            res *= x
            half power each time
            2 4
            1 4
            2 2
            4 1
            8 0

            3 6
            1 6
            3 3
            9 1
            27 0

            onl
        */
        double res = 1;
        long power = abs((long)n);
        while (power) {
            if (power & 1) {
                res *= x;
            }
            x *= x;
            power /= 2;
        }

        if (n < 0) {
            res = 1 / res;
        }
        return res;
    }
};
