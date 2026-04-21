class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        /*
            1 - n
            cannot repeat element
            must be unique set

            push to res when i == k
            dfs:
                for j = i (iterate through all n numbers)
                dfs(j + 1) ensures we cannot repeat the element

            n = 3
            k = 2

            [1, 2]
            [1, 3]
            []

            [1,2]
            [1,3]
            [2,3]

        */
        std::vector<int> combination;
        dfs(n, k, combination, 1);
        return res;
    }

    void dfs(const int n, const int k, std::vector<int>& combination, const int i) {
        if (combination.size() == k) {
            res.push_back(combination);
            return;
        }

        for (int j = i; j <= n; ++j) {
            combination.push_back(j);
            dfs(n, k, combination, j + 1);
            combination.pop_back();
        }
    }
};