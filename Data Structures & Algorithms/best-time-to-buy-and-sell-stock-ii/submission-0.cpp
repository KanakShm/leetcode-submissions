class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            if you can sell it the next day sell it otherwise keep it O(n^2)
            if the next element is greater than the current one add it to the total O(n)
        */

        int res = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i] < prices[i + 1]) {
                res += prices[i + 1] - prices[i];
            }
        }

        return res;
    }
};