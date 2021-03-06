/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector < vector<int> > res;

        if (root == NULL) {
            return res;
        }

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            vector<int> row;
            for (int i = 0; i < n; i++) {
                TreeNode* node = que.front();
                que.pop();
                row.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(row);
        }

        return res;
    }
};
