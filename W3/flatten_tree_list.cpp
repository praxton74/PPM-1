void flatten(TreeNode *root) {
    // edge case
    if(!root)
        return;
    
    while(root) {
        if(root->left) {
            TreeNode *leftRightMost = root->left;
            while(leftRightMost->right)
                leftRightMost = leftRightMost->right;
            leftRightMost->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        // move to the next node
        root = root->right;
    }
}
