/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    /*
        level order traversal bfs. convert to string including NULL
        to decode, create a queue and append the first element
            iterate throught the string and have left = 1 and right = 2
            add the second and third element to the queue
            pop the first element and do while the queue is not empty
    */

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);
        std::string str = "";
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                TreeNode* front = q.front();
                if (front) {
                    str.append(std::to_string(front->val));
                } else {
                    str.append("NULL");
                }

                str.append(",");

                if (front) {
                    q.push(front->left);
                    q.push(front->right);
                }

                q.pop();
            }
        }
        std::cout << str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Get the first segement to push to the queue
        int iter = 0;
        std::string segment = "";
        while (iter < data.size() && data[iter] != ',') {
            segment.push_back(data[iter]);
            iter++;
        }

        if (segment == "NULL") return nullptr;
        if (data[iter] == ',') iter++;

        TreeNode* root = new TreeNode(std::stoi(segment));
        std::queue<TreeNode*> q;
        q.push(root);
        
        // While the q is not empty
        // iterate get the two next elements from the string
        // append to left and right of q.top()
        while (!q.empty() && iter < data.size()) {
            if (data[iter] == ',') {
                iter++;
                continue;
            }

            // get two segments
            std::vector<TreeNode*> vals;
            std::string segment = "";
            while (iter < data.size() && data[iter] != ',') {
                segment.push_back(data[iter]);
                iter++;
            }
            if (segment == "NULL") {
                vals.push_back(nullptr);
            } else {
                TreeNode *node = new TreeNode(std::stoi(segment));
                vals.push_back(node);
            }

            if (data[iter] == ',') iter++;

            segment = "";
            while (iter < data.size() && data[iter] != ',') {
                segment.push_back(data[iter]);
                iter++;
            }
            if (segment == "NULL") {
                    vals.push_back(nullptr);
            } else {
                TreeNode *node = new TreeNode(std::stoi(segment));
                vals.push_back(node);
            }

            TreeNode* top = q.front();
            if (vals.size() > 0) {
                top->left = vals[0];
                if (vals[0]) {
                    q.push(vals[0]);
                }
            }

            if (vals.size() == 2) {
                top->right = vals[1];
                if (vals[1]) {
                    q.push(vals[1]);
                }
            }
            q.pop();
        }
        return root;
    }
};
