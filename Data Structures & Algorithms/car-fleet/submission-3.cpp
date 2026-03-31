#include <array>

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        /*
            sort the array
            stack size is the amount of fleets
            maintain a monotonic increasing stack <how many iterations to reach the target?
            smaller iterations means the car is faster -> add to the stack
            larger values means previous car will catch up.
                -> pop off until the current value < stack.top();
            
            return stack.size();

            [0, 1, 4, 7]
            [10, 5, 3, 3]
        */
        std::vector<std::array<int, 2>> arr;
        for (int i = 0; i < position.size(); ++i) {
            std::array<int,2> container = {position[i], speed[i]};
            arr.push_back(container);
        }
        std::sort(arr.begin(), arr.end(), std::less<std::array<int,2>>());
        
        // Monotonic decreasing stack
        std::stack<double> st;
        for (int i = 0; i < arr.size(); ++i) {
            // ceiling((target - position) / speed)
            double iterations = static_cast<double>((target - arr[i][0])) / static_cast<double>(arr[i][1]);
            if (st.empty() || st.top() > iterations) {
                st.push(iterations);
            } else {
                while (!st.empty() && st.top() <= iterations) {
                    st.pop();
                }
                st.push(iterations);
            }

            std::stack copy = st;
            for (int i = 0; i < st.size(); ++i) {
                std::cout << copy.top() << " ";
                copy.pop();
            }
            std::cout << std::endl;
        }

        return st.size();
    }
};
