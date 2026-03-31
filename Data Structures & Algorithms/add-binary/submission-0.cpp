class Solution {
public:
    string addBinary(string a, string b) {
        std::string res;

        if (a.size() < b.size()) {
            return addBinary(b, a);
        }

        int left = a.size() - 1;
        int right = b.size() - 1;

        int carry = 0;
        while (left >= 0 || right >= 0 || carry != 0) {
            int sum = carry;
            if (left >= 0) {
                sum += a[left] - '0';
                left--;
            }

            if (right >= 0) {
                sum += b[right] - '0';
                right--;
            }

            if (sum >= 2) {
                carry = 1;
            } else {
                carry = 0;
            }

            if (sum % 2 == 0) {
                res.push_back('0');
            } else {
                res.push_back('1');
            }
        }

        std::reverse(res.begin(), res.end());
        return res;
    }
};