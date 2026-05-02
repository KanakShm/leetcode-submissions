class Solution {
public:
    std::vector<std::vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        /*
        Backtracking with i = 1 -> n
        for loop starting at j = i -> Only looking forward
        dfs with j + 1 ->only Cant choose itself again
        base case when combination array reaches k size add to res array and return
        */

        std::vector<int> combination = {};
        dfs(n, 1, combination, k);
        return res;
    }

    void dfs(int n, int i, std::vector<int>& combination, int k) {
        if (combination.size() == k) {
            res.push_back(combination);
            return;
        }

        if (i > n) return;

        combination.push_back(i);
        dfs(n, i + 1, combination, k);
        combination.pop_back();
        dfs(n, i + 1, combination, k);
    }
};