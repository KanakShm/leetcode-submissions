class Solution {
public:
    int n;
    std::vector<std::string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        /*
            adj list <airport, other airport(s)>
            if there are multiple airpoirts in one adj list
            that means that there exists a ticket to come back to
            the current airport.
            we end the dfs if we have used up all the tickets, hashset size is
            the same size as tickets -> true, if there are no more tickets left
            from the current airport to the next -> false. Bubble up true

            <jfk, [kdf hgf]>
            <kdf, jfk>
            <hgf.    >
            dfs through this
            path invalid if we dont visit all the nodes
                for all the neighbours dfs
            
            BUF < HOU >
            HOU < SEA >
            JFK < BUF >

            HOU < JFK >
            SEA < JFK >
            JFK < SEA, HOU >

            to prevent infinite loop, we mark each airport within neighbours
            list as visited or not <airport, bool>
        */

        n = tickets.size() + 1;
        std::unordered_map<std::string, std::vector<std::pair<std::string, bool>>> adj_list;
        for (int i = 0; i < tickets.size(); ++i) {
            adj_list[tickets[i][0]].push_back({tickets[i][1], false});
        }

        for (auto iter = adj_list.begin(); iter != adj_list.end(); ++iter) {
            std::sort(iter->second.begin(), iter->second.end());
        }

        std::string start = "JFK";
        dfs(adj_list, start);
        return res;
    }

    bool dfs(std::unordered_map<std::string, std::vector<std::pair<std::string, bool>>>& adj_list, std::string& airport) {
        res.push_back(airport);
        if (res.size() == n) return true;

        std::vector<std::pair<std::string, bool>> neighbours = adj_list[airport];
    
        for (int i = 0; i < neighbours.size(); ++i) {
            if (neighbours[i].second) continue;
            adj_list[airport][i].second = true;
            if (dfs(adj_list, neighbours[i].first)) return true;
            adj_list[airport][i].second = false;
        }

        res.pop_back();
        return false;
    }
};
