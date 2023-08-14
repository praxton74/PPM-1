void findRightView(TreeNode* root, int level, int &max_level, vector<int> &results) {
    // base case
    if(!root) 
        return;
    if(level > max_level) {
        results.push_back(root->val);
        max_level = level;
    }
    
    findRightView(root->right, level + 1, max_level, results);
    findRightView(root->left, level + 1, max_level, results);
}

vector<int> rightSideView(TreeNode* root) {
    int max_level = -1;
    vector<int> results;
    findRightView(root, 0, max_level, results);
    
    return results;
}
