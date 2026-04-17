class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        /*
            start at each index and iterate forwards until you see
            a third type of tree 
            one hashmap and size cannot reach more than 2
            O(n^2)

            sliding window
            incriment the fruits array until we see 3 types of fruits
            then decrement until our subarray only contains 2 types of fruits
            every increment we add one to our total fruits
            every decrement we decrease our total fruits by one

            hashmap<type, count> if count decreases to 0 remove
            each iteration we check if hashmap size
            [1,2,3,2,3,1,2]
        */

        std::unordered_map<int, int> baskets;
        int left = 0;
        int right = 0;
        int res = 0;
        while (right < fruits.size()) {
            baskets[fruits[right]]++;
            right++;
            while (baskets.size() > 2) {
                baskets[fruits[left]]--;
                if (baskets[fruits[left]] == 0) {
                    baskets.erase(fruits[left]);
                }
                left++;
            }
            res = std::max(res, right - left);
        }
        return res;
    }
};