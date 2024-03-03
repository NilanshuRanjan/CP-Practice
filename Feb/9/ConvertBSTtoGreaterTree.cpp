class Solution {
public:
    vector<TreeNode*> arr;
    void inorder(TreeNode* root){
        if (root == NULL) return;
        TreeNode* temp = root;
        inorder(temp->left);
        arr.push_back(temp);
        inorder(temp->right);
    }

    static bool mysort (TreeNode* a, TreeNode* b){
        return a->val < b->val;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        inorder(root);
        sort(arr.begin(), arr.end(), mysort);

        for (int i = 0; i<arr.size(); i++){
            for (int j = i+1; j<arr.size(); j++){
                arr[i]->val += arr[j]->val;
            }
        }

        return root;
    }
};
