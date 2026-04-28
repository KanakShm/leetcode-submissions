class Solution {
public:
    string predictPartyVictory(string senate) {
        /*
            Party member gets rid of the rights of the next
            party member of the opposite party

            push all radiants and dires to their own queues

            iterate through the senate list and pop both queues and
            push back the senate member that currently has the vote right

            queue<index> and while both queues are not empty, pop the one
            that has the smaller index and push to the end, pop the one that
            has a larger index and dont append to the end.
        */

        std::queue<int> radiant;
        std::queue<int> dire;
        for (int i = 0; i < senate.size(); ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }

        while (!radiant.empty() && !dire.empty()) {
            int radiant_front = radiant.front();
            int dire_front = dire.front();

            radiant.pop();
            dire.pop();

            if (radiant_front < dire_front) {
                radiant.push(radiant_front + senate.size());
            } else {
                dire.push(dire_front + senate.size());
            }
        }

        if (!radiant.empty()) return "Radiant";
        return "Dire";
    }
};