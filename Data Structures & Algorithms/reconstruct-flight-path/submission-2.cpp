class Solution {
public:
    std::vector<std::string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /*
            hashmap airpoirt, all tickets from that airport

            DFS
                add when we have exhausted the current airport
                strings need to be sorted in reverse order

                a b
                b c
                c a
                res = a b c a
                res = a c b a
                when you visit an airport you delete that ticket
                means you iterate from the back
        */
        std::sort(tickets.rbegin(), tickets.rend());
        std::unordered_map<std::string, std::vector<std::string>> adj_list;
        for (int i = 0; i < tickets.size(); ++i) {
            adj_list[tickets[i][0]].push_back(tickets[i][1]);
        }

        std::string start = "JFK";
        dfs(adj_list, start);
        std::reverse(res.begin(), res.end());
        return res;
    }

    void dfs(std::unordered_map<std::string, std::vector<std::string>>& adj_list, std::string& airport) {
        while (!adj_list[airport].empty()) {
            std::string ticket = adj_list[airport].back();
            // delete the ticket
            adj_list[airport].pop_back();
            dfs(adj_list, ticket);
        }
        res.push_back(airport);
    }
};
