class Solution {
public:
    /*
        4357
        4357
    */
    int64_t decode(const std::string num) {
        int64_t res = 0;
        for (int i = 0; i < num.size(); ++i) {
            res *= 10;
            res += static_cast<int64_t>(num[i] - '0');
        }
        return res;
    }
    string multiply(string num1, string num2) {
        /*
            convert numbers to integers cast to int (num - '0')
            multiply
            cast to string or just mod divide and append
        */

        int64_t a = decode(num1);
        int64_t b = decode(num2);
        std::cout << a << " " << b << std::endl;
        int64_t res = a * b;

        std::string output = "";
        while (res > 0 || output.empty()) {
            char digit = static_cast<char>((res % 10) + '0');
            output.push_back(digit);
            res /= 10;
        }
        std::reverse(output.begin(), output.end());
        return output;
    }
};
