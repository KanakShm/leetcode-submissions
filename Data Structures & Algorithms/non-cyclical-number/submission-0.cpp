class Solution {
public:
    bool isHappy(int n) {
        /*
            get the digits and square them
            put the result in a hashmap
            check if we have seen the result before and return false if we have
            if the number is a 1 then we return tru
        */
        std::unordered_map<int, int> umap;
        while (true) {
            int val = 0;
            while (n != 0) {
                int digit = n % 10;
                val += (digit * digit);
                n = n / 10;
            }
            if (val == 1) return true;

            if (umap.find(val) == umap.end()) {
                umap[val]++;
            } else {
                return false;
            }
            n = val;
        }
    }
};
