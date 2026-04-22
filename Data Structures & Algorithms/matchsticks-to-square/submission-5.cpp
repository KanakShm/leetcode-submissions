class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        /*
            backtracking

            cannot pick the same matchstick again so recurse with j + 1
            can pick any matchstick so start with j = 0
            visited array so we dont pick the same matchstick

            bubble up true result and return
            each level we += to one of the four elements of square array
            dfs(j + 1)
            keep adding until we see square[k] > target -> return false
            if square[k] = target dfs with k + 1
            return true only when k == 4

            optimsation 1: sort the array and first time square reaches more than
            target break from the loop -> no other combo will equal target

            optimisation 2: prune siblings so we only consider unique combinations and
            not permutations:
                1111333334
                [[1]]
        */

        int target = 0;
        for (int i = 0; i < matchsticks.size(); ++i) {
            target += matchsticks[i];
        }

        if (target == 0 || target % 4 != 0) return false;
        target /= 4;

        std::vector<int> square(4, 0);
        std::vector<bool> visited(matchsticks.size(), false);
        std::sort(matchsticks.rbegin(), matchsticks.rend());
        return dfs(matchsticks, square, 0, visited, target, 0);
    }

    /*
        [2,4,3,2,1,4]
        [4,4,0,0]
    */
    bool dfs(std::vector<int>& matchsticks, std::vector<int>& square, int k, std::vector<bool>& visited, int target, int i) {
        if (k == 4) return true;
        if (square[k] == target) return dfs(matchsticks, square, k + 1, visited, target, 0);

        for (int j = i; j < matchsticks.size(); ++j) {
            if (visited[j]) continue;
            if (square[k] + matchsticks[j] > target) continue;
            square[k] += matchsticks[j];
            visited[j] = true;
            if (dfs(matchsticks, square, k, visited, target, j + 1)) {
                return true;
            }
            square[k] -= matchsticks[j];
            visited[j] = false;
        }

        return false;
    }
};