#include <array>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::vector<std::array<int, 3>> heap;
        int x1 = 0;
        int y1 = 0;
        for (int i = 0; i < points.size(); ++i) {
            int x2 = points[i][0];
            int y2 = points[i][1];

            int dist2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
            heap.push_back(std::array<int, 3>{{dist2, x2, y2}});
            std::push_heap(heap.begin(), heap.end(), std::greater<std::array<int, 3>>());
        }

        std::vector<std::vector<int>> res;
        for (int i = 0; i < k; ++i) {
            int x = heap[0][1];
            int y = heap[0][2];
            std::pop_heap(heap.begin(), heap.end(), std::greater<std::array<int, 3>>());
            heap.pop_back();

            res.push_back(std::vector<int>{x, y});
        }

        return res;
    }
};
