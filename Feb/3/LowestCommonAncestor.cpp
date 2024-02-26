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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q || root == NULL){
            return root;
        }

        TreeNode* node1 = lowestCommonAncestor(root->left, p, q);
        TreeNode* node2 = lowestCommonAncestor(root->right, p, q);
        if (node1 == NULL){
            return node2;
        }
        else if (node2 == NULL){
            return node1;
        }
        else {
            return root;
        }
    }
};
