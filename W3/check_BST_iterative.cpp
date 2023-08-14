bool isValidBST(TreeNode *root) {
    // edge case
    if(!root)
        return true;
    stack<TreeNode*> s;
    TreeNode *prev = NULL;

    while(!s.empty() || root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if(prev && root->val <= prev->val)
            return false;
        prev = root;
        root = root->right;
    }
    return true;
}
