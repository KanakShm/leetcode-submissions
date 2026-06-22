class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        /*
            use a stack
            if the top of the stack is going in a diff direction to the curret
            asteroid
                pop it and push the one that is higher in magnitude
            
            2 4 -4 1
            2

            7 -3 9 -5 4
            7 9 -5

            10 2 -5
        */

        std::vector<int> st;
        for (int i = 0; i < asteroids.size(); ++i) {
            if (st.empty()) {
                st.push_back(asteroids[i]);
                continue;
            }
            
            bool collision = false;
            int asteroid = asteroids[i];
            while (!st.empty() && (st.back() > 0 && asteroid < 0)) {
                if (std::abs(asteroid) < std::abs(st.back())) {
                    collision = true;
                    break;
                } else if (std::abs(asteroid) == std::abs(st.back())) {
                    collision = true;
                    st.pop_back();
                    break;
                } else {
                    st.pop_back();
                }
            }

            if (!collision) st.push_back(asteroid);
        }
        return st;
    }
};