class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        /*
            monotonic increasing stack
            go through the array if an element is negative peek the top element of the
            stack: while the negative is greater than tht top pop
        */

        std::vector<int> space;
        for (int i = 0; i < asteroids.size(); ++i) {
            while (!space.empty() && space.back() > 0 && asteroids[i] < 0 && space.back() < std::abs(asteroids[i])) {
                space.pop_back();    
            }

            if (!space.empty() && asteroids[i] < 0 && space.back() == std::abs(asteroids[i])) {
                space.pop_back();
                continue;
            }

            if (space.empty() || space.back() < 0 || asteroids[i] > 0) {
                space.push_back(asteroids[i]);
            }
        }

        return space;
    }
};