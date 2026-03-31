class Solution {
public:
    int getSum(int a, int b) {
        /*
            10100
            11110
           110010
           100010
          1101010

           start from right most bit and add together
           if result is 0, append 0
           if result is 1, append 1
           if result is 2, append 1 and carry
           append to a vector and then at the end iterate through it and convert back to int
        */
        int carry = 0;
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int a_bit = (a >> i) & 1;
            int b_bit = (b >> i) & 1;
            int curr_bit = a_bit ^ b_bit ^ carry;
            res |= (curr_bit) << i;
            carry = (a_bit + b_bit + carry) >= 2 ? 1 : 0;
        }
        return res;
    }
};
