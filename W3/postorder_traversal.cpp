vector<int> postorderTraversal(TreeNode *root) {
    // base case
    if(!root)
        return {};
    
    vector<int> results;
    stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode *front = s.top();
        results.push_back(front->val);
        if(front->left)
            s.push(front->left);
        if(front->right)
            s.push(front->right);
    }
    reverse(results.begin(), results.end());
    return results;
}
