class Solution {
public:
    int tribonacci(int n) {
        /*
            build the dp array up till n + 1 (0 indexed) and return that
            only keep track of 3 variables and update them as we go
        */
        if (n == 1 || n == 2) return 1;
        if (n == 0) return 0;

        int first = 0;
        int second = 1;
        int third = 1;

        for (int i = 3; i <= n; ++i) {
            int next = first + second + third;
            first = second;
            second = third;
            third = next;
        }

        return third;
    }
};