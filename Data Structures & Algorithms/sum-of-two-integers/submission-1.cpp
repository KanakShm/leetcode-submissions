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
        std::vector<int> result;
        int carry = 0;
        for (size_t i = 0; i < 32; ++i) {
            int curr_a = (a >> i) & 1;
            int curr_b = (b >> i) & 1;

            std::cout << curr_a << " " << curr_b << " " << carry << std::endl;
            if (curr_a + curr_b + carry == 0) {
                result.push_back(0);
                carry = 0;
            } else if (curr_a + curr_b + carry == 1) {
                result.push_back(1);
                carry = 0;
            } else if (curr_a + curr_b + carry == 2) {
                result.push_back(0);
                carry = 1;
            } else if (curr_a + curr_b + carry > 2) {
                result.push_back(1);
                carry = 1;
            }
        }

        if (carry) {
            result.push_back(1);
        }

        for (int i = 0; i < result.size(); i++) {
            std::cout << result[i];
        }
        int32_t output = 0;
        // first element of vector should be the last bit
        for (size_t i = 0; i < 32; ++i) {
            output |= result[i] << i;
        }

        return output;
    }
};
