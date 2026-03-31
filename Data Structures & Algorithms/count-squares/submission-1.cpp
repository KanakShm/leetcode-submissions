class CountSquares {
public:
    CountSquares() {

    }
    
    int64_t getKey(int x, int y) {
        return (int64_t)((int64_t(x) << 32) | y);
    }

    void add(vector<int> point) {
        umap[getKey(point[0], point[1])]++;
        points.push_back(std::make_pair(point[0], point[1]));
    }
    
    int count(vector<int> point) {
        int count = 0;
        for (int i = 0; i < points.size(); ++i) {
            int xdiff = point[0] - points[i].first;
            int ydiff = point[1] - points[i].second;
            uint64_t corner1 = getKey(point[0], points[i].second);
            uint64_t corner2 = getKey(points[i].first, point[1]);
            if (point[0] == points[i].first && point[1] == points[i].second) continue;
            if (std::abs(xdiff) != std::abs(ydiff)) continue;
            if (umap.find(getKey(point[0], points[i].second)) == umap.end() ||
                umap.find(getKey(points[i].first, point[1])) == umap.end())
                continue;
            count += umap[getKey(point[0], points[i].second)] * umap[getKey(points[i].first, point[1])];
        }
        return count;
    }

private:
    /*
        create one hashmap shift x left by 32 and or with y
        create helper function to get the key for that
        in the count function we iterate over all the points, check if the distance in x and y 
        are the same. If they are then check if the other corresponding points are in the hashmap.
        increment count
    */
    std::unordered_map<int64_t, int> umap;
    std::vector<std::pair<int, int>> points;
};
