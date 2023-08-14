
void left_helper(Node *root, int level, int &max_level, vector<int> &results) {
    // base case
    if(!root)
        return;
    if(level > max_level) {
        max_level = level;
        results.push_back(root->data);
    }
    left_helper(root->left, level + 1, max_level, results);
    left_helper(root->right, level + 1, max_level, results);
}

vector<int> leftView(Node *root) {
    vector<int> results;
    int max_level = -1;
    left_helper(root, 0, max_level, results);

    return results;
}
