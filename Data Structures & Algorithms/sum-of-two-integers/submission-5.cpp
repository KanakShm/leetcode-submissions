class Solution {
public:
    int getSum(int a, int b) {
        /*
            10100
            11110
            
           110010

           100010
          1101010

           Add a with b (a^b)
           the carries happened at (a&b) bit location
           then set b = that result and a ^ b again.
           you always set the result to a and the carries to b.
        */
        while (b != 0) {
            int partial_sum = a ^ b;
            int carries = (a & b) << 1;
            a = partial_sum;
            b = carries;
        }
        return a;
    }
};
