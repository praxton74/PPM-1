

TreeNode *build_helper(vector<int> &preorder, vector<int> &inorder, int start, int end, int &pre_index) {
    // base case
    if(start > end)
        return NULL;
    TreeNode *root = new TreeNode(preorder[pre_index]);
    int idx = -1;
    for(int i = start; i <= end; i++) {
        if(inorder[i] == preorder[pre_index]) {
            idx = i;
            break;
        }
    }
    pre_index++; 
    root->left = build_helper(preorder, inorder, start, idx - 1, pre_index);
    root->right = build_helper(preorder, inorder, idx + 1, end, pre_index);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size(), pre_index = 0;
    return build_helper(preorder, inorder, 0, n - 1, pre_index);
}
