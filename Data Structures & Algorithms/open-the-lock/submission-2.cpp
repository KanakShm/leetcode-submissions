class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        /*
            0000

            1000

            Adj list for 0000
                0001
                0010
                0100
                1000

                0009
                0090
                0900
                9000
            Add all these values to a queue and pop one whole layer at a time
            if one of the values match target return count (updates one increment each layer)
            if dont push any element that is contained within deadends
            visited array push element
        */

        std::unordered_set<std::string> deadends_map;
        std::unordered_set<std::string> visited;
        for (int i = 0; i < deadends.size(); ++i) {
            deadends_map.insert(deadends[i]);
        }

        std::string lock = "0000";
        int count = 0;

        std::queue<std::string> q;

        if (!deadends_map.count(lock)) {
            q.push(lock);
            visited.insert(lock);
        }
        
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                std::string top = q.front();

                if (top == target) return count;

                q.pop();

                for (int i = 0; i < top.size(); ++i) {
                    std::string new_combination = top;
                    int number = top[i] - '0';
                    int new_number = (number + 1) % 10;
                    new_combination[i] = new_number + '0';

                    if (!deadends_map.count(new_combination) && 
                        !visited.count(new_combination)) {
                            visited.insert(new_combination);
                            q.push(new_combination);
                        }
                    
                    new_number = number - 1;
                    if (new_number < 0) new_number = 9;

                    new_combination[i] = new_number + '0';

                     if (!deadends_map.count(new_combination) && 
                        !visited.count(new_combination)) {
                            visited.insert(new_combination);
                            q.push(new_combination);
                        }
                }
            }
            count++;
        }

        return -1;
    }
};