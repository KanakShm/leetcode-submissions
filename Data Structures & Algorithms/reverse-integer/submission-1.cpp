class Solution {
public:
    int reverse(int x) {
        /*
            00000100 11010011
            00000100 11010010
            00000100 11010001

            450469
            450466. 664054

            00010000 11100001

            reverse the input then check if its greater thant INT_MIN/MAX
            keep track of result = 0;
            while input != 0
            res = (res * 10) + digit
            input = input % 10;

        */
        int32_t chopped_max = INT_MAX / 10;
        int32_t chopped_min = INT_MIN / 10;
        int res = 0;
        while (x) {
            int digit = x % 10;
            if (res > chopped_max || res == chopped_max && digit > INT_MAX % 10) {
                return 0;
            } else if (res < chopped_min || res == chopped_min && digit < INT_MIN % 10) {
                return 0;
            }
            x = x / 10;
            res = res * 10 + digit;
        }
        return res;
    }
};
