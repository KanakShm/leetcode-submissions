class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        /*
            breadth first search to ensure first time we reach target we are minimum
            0000 - 0001, 0010, 0100, 1000
            when we hit a dead end just continue and done add any neihbours to the queue
        */
        std::unordered_set<std::string> uset;
        std::unordered_set<std::string> visited;
        for (int i = 0; i < deadends.size(); ++i) {
            uset.insert(deadends[i]);
        }

        int res = -1;
        std::queue<std::vector<std::string>> q;

        q.push({"0000"});
        visited.insert("0000");

        while (!q.empty()) {
            std::vector<std::string> top = q.front();
            q.pop();
            res++;

            // Iterate through top string vector and append a new vector of all of i's neighbours
            std::vector<std::string> neighbours;
            for (int i = 0; i < top.size(); ++i) {

                // if we find the target return res, dont add any neighbours of deadends
                if (top[i] == target) return res;
                if (uset.count(top[i])) continue;

                for (int j = 0; j < 4; ++j) {
                    std::string next_turn_forward = top[i];
                    std::string next_turn_backward = top[i];

                    int turn_forward = static_cast<int>(top[i][j] - '0') + 1;
                    int turn_backward = static_cast<int>(top[i][j] - '0') - 1;
                    
                    if (turn_forward > 9) turn_forward = 0;
                    if (turn_backward < 0) turn_backward = 9;

                    next_turn_forward[j] = static_cast<char>(turn_forward + '0');
                    next_turn_backward[j] = static_cast<char>(turn_backward + '0');

                    if (!visited.count(next_turn_forward)) {
                        neighbours.push_back(next_turn_forward);
                        visited.insert(next_turn_forward);
                    }

                    if (!visited.count(next_turn_backward)) {
                        neighbours.push_back(next_turn_backward);
                        visited.insert(next_turn_backward);
                    }
                }
            }

            if (!neighbours.empty()) {
                q.push(neighbours);
            }
        }

        return -1;
    }
};