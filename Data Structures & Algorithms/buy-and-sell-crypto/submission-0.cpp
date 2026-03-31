class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            two pointers both at 0 and 1
            if r >= l move the right pointer forward
            if r < l left = right. right++

                      l r
            [10,8,7,5,2]

            max = 8
                     l         r
            [3,5,2,2,1,5,2,5,3,9]
        */

        int max_profit = 0;
        int left = 0;
        int right = left + 1;
        while (right < prices.size()) {
            max_profit = std::max(prices[right] - prices[left], max_profit);
            if (prices[left] > prices[right]) {
                left = right;
            }
            right++;
        }
        return max_profit;
    }
};
