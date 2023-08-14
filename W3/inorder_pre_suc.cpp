void findPreSuc(Node *root, Node *&pre, Node *&succ, int key) {
    // base case
    if(!root)
        return;
    if(root->key > key) {
        succ = root;
        return findPreSuc(root->left, pre, succ, key);
    }
    else if(root->key < key) {
        pre = root;
        return findPreSuc(root->right, pre, suc, key);
    }
    else {
        if(root->left)
            findPreSuc(root->left, pre, suc, key);
        if(root->right)
            findPreSuc(root->right, pre, suc, key);
    }
}
