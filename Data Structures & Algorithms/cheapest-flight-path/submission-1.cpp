class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /*
            Dijkestra
            min heap <price of ticket>

            adj list of flight, vector of pair destinations, price
            dijkestra starting at src with min heap
                remove one element at a time
                if we hit k == 0 then dont add any current destinations to the
                heap and increment k by 1


            Input: n = 4, flights = [[0,1,200],[1,2,100],[1,3,300],[2,3,100]], 
            src = 0, dst = 3, k  = 1

            0 1,200
            1 2,100 3,300
            2 3,100
            3
        */

        std::unordered_map<int, std::vector<std::vector<int>>> adj_list;
        for (int i = 0; i < n; ++i) {
            adj_list[i] = {};
        }

        for (int i = 0; i < flights.size(); ++i) {
            adj_list[flights[i][0]].push_back({flights[i][1], flights[i][2], 0});
        }

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<>> min_heap;

        k++;
        min_heap.push({0, src, k});

        std::vector<int> visited(n, -1);
        int cost = 0;
        while (!min_heap.empty()) {
            int price = min_heap.top()[0];
            int airport = min_heap.top()[1];
            int stops = min_heap.top()[2];

            min_heap.pop();
            if (airport == dst) return price;

            if (stops == 0 || visited[airport] >= stops) continue;
            visited[airport] = stops;

            // Each node contains the min cost to get there
            std::vector<std::vector<int>> tickets = adj_list[airport];
            for (int i = 0; i < tickets.size(); ++i) {
                min_heap.push({price + tickets[i][1], tickets[i][0], stops - 1});
            }
        }

        return -1;
    }
};
