Node *LCA(node *root, int n1, int n2) {
    if(min(n1, n2) > root->data)
        return LCA(root->right, n1, n2);
    if(max(n1, n2) < root->data)
        return LCA(root->left, n1, n2);
    return root;
}
