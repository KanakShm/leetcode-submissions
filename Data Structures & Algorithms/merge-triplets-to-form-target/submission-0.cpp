#include <array>
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        /*  
            5 5 5
            1 2 3
            5 10 2
            1 5 3
            5 2 5

            dont consider any values that are greater than target[i]
            for all the values less than or equal to their corresponding
            index in target, we only need to find one for each that is matching target
        */
        std::array<int, 3> res = {0, 0, 0};
        for (int i = 0; i < triplets.size(); ++i) {
            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2]) {
                    if (triplets[i][0] == target[0]) {
                        res[0] = 1;
                    }

                    if (triplets[i][1] == target[1]) {
                        res[1] = 1;
                    }

                    if (triplets[i][2] == target[2]) {
                        res[2] = 1;
                    }
                }
        }

        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != 1) {
                return false;
            }
        }

        return true;
    }
};
