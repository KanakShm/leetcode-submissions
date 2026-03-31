class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int64_t res = 0;
        for (int i = 0; i < digits.size(); ++i) {
            res += digits[i] * std::pow(10, digits.size() - 1 - i);
        }
        res += 1;
        std::vector<int> output;
        while (res != 0) {
            output.push_back(res % 10);
            res /= 10;
        }
        std::reverse(output.begin(), output.end());
        return output;
    }
};
