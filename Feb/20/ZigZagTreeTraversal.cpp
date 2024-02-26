class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans;
    	int var = 0, pos=0;
    	if (root == NULL) return ans;
    	
    	queue<Node*> q;
    	q.push(root);
    	
    	while (!q.empty()){
    	    int size = q.size();
    	    for (int i = 0; i<size; i++){
    	        Node* node = q.front();
    	        q.pop();
    	        if (node->right != NULL) q.push(node->right);
    	        if (node->left != NULL) q.push(node->left);
    	        ans.push_back(node->data);
    	    }
    	    if (var%2 == 0){
    	        reverse(ans.begin()+pos, ans.end());
    	    }
    	    pos = ans.size();
    	    var ++;
    	}
    	
    	return ans;
    }
};
