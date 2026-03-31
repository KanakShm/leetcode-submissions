class Solution {
public:
    /*
        4357
        4357
    */

    string multiply(string num1, string num2) {
        /*
            multiply like we do on paper
            get the final value j of num2 and multiply with i of num2
            keep track of a carry
            after we finish one iteration of i we add current result to res
            after we finish one iteration multuply the current result by 10^i
        */
        std::vector<int> result(num1.size() + num2.size(), 0);
        for (int j = num2.size() - 1; j >= 0; --j) {
            int digit2 = static_cast<int>(num2[j] - '0');
            for (int i = num1.size() - 1; i >= 0; --i) {
                int digit1 = static_cast<int>(num1[i] - '0');
                int mult = digit1 * digit2 + result[i + j + 1];

                result[j + i + 1] = (mult) % 10;
                result[j + i] += mult / 10;
            }
        }
        
        std::string output = "";
        for (int i = 0; i < result.size(); ++i) {
            if (output.empty() && result[i] == 0) continue;
            output += static_cast<char>(result[i] + '0');
        }
        return output.empty() ? "0" : output;
    }
};
