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
class Solution {
public:
    vector<vector<int>> bfs (TreeNode* root){
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> lvl;
            int size = q.size();
            for (int i = 0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
                lvl.push_back(node->val);
            }
            ans.push_back(lvl);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        for (auto i: bfs(root)){
            ans.push_back(i[i.size()-1]);
        }
        return ans;
    }
};
