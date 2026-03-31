class Solution {
public:
    std::vector<int> cache;
    int minCostClimbingStairs(vector<int>& cost) {
        /*
            backtrack
            running cost will be current cost + i + 1 or i + 2
            current cost = min dfs left and dfs right
        */
        cache.resize(cost.size(), -1);
        return std::min(dfs(cost, 0), dfs(cost, 1));
    }

    int dfs(std::vector<int>& cost, int i) {
        if (i >= cost.size() - 2) {
            return cost[i];
        }
        if (cache[i] != -1) return cache[i];
        cache[i] = cost[i] + std::min(dfs(cost, i + 1), dfs(cost, i + 2));
        return cache[i];
    }
};
