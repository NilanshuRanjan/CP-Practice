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
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, long long int>> q;
        if (root==NULL) return 0;
        q.push({root, 0});
        while (!q.empty()){
            int size = q.size(), first = 0, last = 0;
            int m = q.front().second;
            for (int i = 0; i<size; i++){
                long long int cur_id = q.front().second - m;
                TreeNode* node = q.front().first;
                q.pop();
                if (i == 0) first = cur_id;
                else if (i == size-1) last = cur_id;
                if (node->left) q.push({node->left, cur_id*2+1});
                if (node->right) q.push({node->right, cur_id*2+2});
            }
            ans = max(last-first+1, ans);
        }
        return ans;
    }
};
