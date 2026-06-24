class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        /*
            choose k numbers
            n from 1 to n
            dfs
                start of at 1
                for loop at j = i
                i starts at 1
                j until we equal n
                dfs(j + 1)
                base case if the length of the array = k
            
            1 2 3 4 5 6 7
        */
        std::vector<int> combination = {};
        dfs(n, k, 1, combination);
        return res;
    }

    void dfs(int n, int k, int i, std::vector<int>& combination) {
        if (combination.size() == k) {
            res.push_back(combination);
            return;
        }

        for (int j = i; j <= n; ++j) {
            combination.push_back(j);
            dfs(n, k, j + 1, combination);
            combination.pop_back();
        }
    }
};