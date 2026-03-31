class Solution {
public:
    int climbStairs(int n) {
        /*
            recursive approach either pick one step or pick two
            have a cache vector where i corresponds to the step
            at each step, we first check if cache[i] contains the answer else append the answer
        */

        std::vector<int> cache(n, -1);
        return dfs(cache, n, 0);
    }

    int dfs(std::vector<int>& cache, int n, int i) {
        if (i == n) return 1;
        if (i > n) return 0;

        if (cache[i] != -1) return cache[i];
        return cache[i] = dfs(cache, n, i + 1) + dfs(cache, n, i + 2);
    }
};
