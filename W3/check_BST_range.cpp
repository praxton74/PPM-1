bool isBST(TreeNode *root, long long min_val = -1e10, long long max_val = 1e10) {
    // base case
    if(!root)
        return true;
    if(root->val > min_val && root->val < max_val) {
        if(isBST(root->left, min_val, root->val) && isBST(root->right, root->val, max_val) 
            return true;
    }
    return false;
}

bool isValidBST(TreeNode *root) {
    return isBST(root);
}
