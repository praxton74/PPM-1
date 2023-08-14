bool isMirror(TreeNode *ls, TreeNode *rs) {
    // base cases
    if(!ls && !rs)
        return true;
    if(!ls || !rs)
        return false;
    if(ls->val != rs->val)
        return false;
    return isMirror(ls->left, rs->right) && isMirror(ls->right, rs->left);
}

bool isSymmetric(TreeNode *root) {
    return isMirror(root, root);
}
