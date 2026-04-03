class Twitter {
    /*
        hashmap<id, hashset of all the users following>
        hashmap<id, vector of pair<timestamp, post>

        post tweet -> append to the vector of posts with current timestamp
        get news feed -> get all the users the user is following
            iterate through this list and get the final value of each post of the followed user
            append to min heap
            heap <timestamp, tweet, index, author>
            while (min heap is not empty and res.size() > 10)
                pop from the heap
                append that to res
                append the next element down to the heap
                push heap
        follow -> insert into following hashmap/hashset
        unfollow -> delete from hashset
    */
public:
    Twitter() : timestamp(0) {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back(std::make_pair(timestamp, tweetId));
        timestamp++;
    }
    
    vector<int> getNewsFeed(int userId) {
        followings[userId].insert(userId);
        std::unordered_set<int> following_list = followings[userId];
        std::vector<std::vector<int>> heap;
        for (auto iter = following_list.begin(); iter != following_list.end(); iter++) {
            std::vector<std::pair<int, int>> feed = posts[*iter];
            if (!feed.empty()) {
                int idx = feed.size() - 1;
                int timestamp = feed[idx].first;
                int tweetId = feed[idx].second;
                int author = *iter;

                heap.push_back({timestamp, idx, tweetId, author});
                std::push_heap(heap.begin(), heap.end(), std::less<std::vector<int>>());
            }
        }

        std::vector<int> res;
        while (!heap.empty() && res.size() < 10) {
            std::vector<int> top = heap[0];
            std::pop_heap(heap.begin(), heap.end(), std::less<std::vector<int>>());
            heap.pop_back();
            
            int timestamp = top[0];
            int idx = top[1];
            int tweetId = top[2];
            int author = top[3];

            res.push_back(tweetId);

            if (idx <= 0) continue;
            // Go back to the posts created by the author and retreive the next one down
            std::pair<int, int> post = posts[author][idx - 1];
            int new_timestamp = post.first;
            int new_tweetId = post.second;
            heap.push_back({new_timestamp, idx - 1, new_tweetId, author});
            std::push_heap(heap.begin(), heap.end(), std::less<std::vector<int>>());
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followings[followerId].find(followeeId) != followings[followerId].end()) {
            followings[followerId].erase(followeeId);
        }
    }

private:
    int timestamp;
    std::unordered_map<int, unordered_set<int>> followings;
    std::unordered_map<int, std::vector<std::pair<int, int>>> posts;
};
