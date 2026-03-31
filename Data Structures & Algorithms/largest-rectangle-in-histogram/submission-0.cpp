#include <array>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
            max area will be current bar to the first bar thats smaller
            iterate forward and get the max for each bar and return the largest?
            [4,7,3,6,4,5,6]

            [3,7,5,1]
            st: [(1,3)]

            [0,3,2,1,0]
            [0,(1,1), (0,4)]
            [1,2,3,4]
        */
        std::stack<std::array<int, 2>> st;
        int max_area = 0;
        for (int i = 0; i < heights.size(); ++i) {
            int height = heights[i];
            int idx = i;
            while (!st.empty() && st.top()[0] > height) {
                idx = st.top()[1];
                max_area = std::max(st.top()[0] * (i - idx), max_area);
                std::cout << max_area << std::endl;

                st.pop();
            }
            st.push({height, idx});
            // std::stack<std::array<int, 2>> copy = st;
            // while (!copy.empty()) {
            //     std::cout << copy.top()[0] <<  " " << copy.top()[1] << ", ";
            //     copy.pop();
            // }
            // std::cout << std::endl;

        }

        while (!st.empty()) {
            int width = heights.size() - st.top()[1];
            max_area = std::max(st.top()[0] * width, max_area);
            st.pop();
        }

        return max_area;
    }
};
