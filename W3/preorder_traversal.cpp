vector<int> preorderTraversal(TreeNode *root) {
    // base case
    if(!root)
        return {};
    
    vector<int> results;
    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty()) {
        TreeNode *front = s.top();
        s.pop();
        results.push_back(front->val);
        if(front->right)
            s.push(front->right);
        if(front->left)
            s.push(front->left);
    }
    return results;
}
