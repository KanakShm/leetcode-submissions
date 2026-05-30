class Twitter {
public:
    std::unordered_map<int, std::unordered_set<int>> follower_map;
    std::unordered_map<int, std::vector<int>> tweet_map;
    Twitter() {
        /*
            adjacecny list with user and followed accounts including the user themselves
            each user has a list of tweets

            following hashmap<user, vector of users>
            hashmap<user, vector of tweet ids they posted>

            get news feed gets the vector of users the user follows, iterates through
            all of their tweets and puts them in a max heap O(n) then pops 10 times
                - goes through the last tweet of every user and stores in a max heap
                - when a users tweet gets popped from the heap, a new tweet is added from that same
                user
        */
    }
    
    void postTweet(int userId, int tweetId) {
        tweet_map[userId].push_back(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        // Go to the vector of followers the user has, upload the last recent tweet from every user to pq

        std::priority_queue<std::vector<int>> max_heap;
        follow(userId, userId);
        
        std::unordered_set<int> followings_set = follower_map[userId];
        for (auto iter = followings_set.begin(); iter != followings_set.end(); ++iter) {
            if (tweet_map[*iter].empty()) continue;
            max_heap.push({tweet_map[*iter].back(), *iter, 1});
        }

        std::vector<int> res;
        while (!max_heap.empty() && res.size() < 10) {
            std::vector<int> top = max_heap.top();
            max_heap.pop();

            int tweet = top[0];
            int user = top[1];
            int end = top[2];

            res.push_back(tweet);

            std::vector<int> tweets = tweet_map[user];
            if ((int)tweets.size() - 1 - end >= 0)
                max_heap.push({tweets[tweets.size() - 1 - end], user, end + 1});
        }

        unfollow(userId, userId);
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follower_map[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower_map[followerId].erase(followeeId);
    }
};
