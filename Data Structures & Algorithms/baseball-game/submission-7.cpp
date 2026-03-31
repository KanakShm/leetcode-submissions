class Solution {
public:
    int calPoints(vector<string>& operations) {
        /*
            create a stack pop twice and add if +
        */
        std::vector<int> st;
        for (int i = 0; i < operations.size(); ++i) {
            if (operations[i] == "+" && st.size() >= 2) {
                int score = st[st.size() - 1] + st[st.size() - 2];
                st.push_back(score);
            } else if (operations[i] == "C" && st.size() >= 1) {
                st.pop_back();
            } else if (operations[i] == "D" && st.size() >= 1) {
                st.push_back((st[st.size() - 1]) * 2);
            } else {
                st.push_back(std::stoi(operations[i]));
            }
        }

        int res = 0;
        for (int i = 0; i < st.size(); ++i) {
            res += st[i];
        }

        return res;
    }
};