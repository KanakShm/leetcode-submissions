#include <array>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
            stack<int>
            if the current element is greater than the top element then pop
            if its equal to or less than then push
            
            keep popping until the current element is less than or equal to top
            if the current element is less than top then push

            st: 40
             r: 1 4 1 2 1 

            [40, 30, 35]
        */

        std::stack<std::array<int, 2>> st;
        std::vector<int> result(temperatures.size());
        for (int i = 0; i < temperatures.size(); ++i) {
            if (st.empty()) {
                std::array<int, 2> curr_temp = {temperatures[i], i};
                st.push(curr_temp);
                continue;
            }
            if (temperatures[i] > st.top()[0]) {
                while (!st.empty() && temperatures[i] > st.top()[0]) {
                    int idx = st.top()[1];
                    result[idx] = i - idx;
                    st.pop();
                }
            }
            std::array<int, 2> curr_temp = {temperatures[i], i};
            st.push(curr_temp);
        }
        return result;
    }
};
