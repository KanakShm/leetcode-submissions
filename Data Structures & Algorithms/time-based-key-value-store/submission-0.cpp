
#include <array>

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        std::string ts = std::to_string(timestamp);

        if (umap.find(key) == umap.end()) {
            umap[key].push_back(std::array<std::string, 2>{{value, ts}});
        } else {
            umap[key].push_back(std::array<std::string, 2>{{value, ts}});
        }
    }
    
    string get(string key, int timestamp) {
        std::vector<std::array<std::string, 2>> states = umap[key];

        int high = states.size() - 1;
        int low = 0;
        std::string prev_mood = "";
        while (low <= high) {
            int mid = (low + high) / 2;
            std::array<std::string, 2> curr = states[mid];
            int ts = std::stoi(curr[1]);
            if (ts == timestamp) {
                return curr[0];
            }
            if (ts > timestamp) {
                high = mid - 1;
            } else {
                prev_mood = curr[0];
                low = mid + 1;
            }
        }
        return prev_mood;
    }

private:
    std::unordered_map<std::string, std::vector<std::array<std::string, 2>>> umap;
};
