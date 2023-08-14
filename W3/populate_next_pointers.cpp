Node *connect(Node *root) {
    // edge case
    if(!root)
        return NULL;

    queue<Node*> q;
    q.push(root);
    Node *curr;
    while(!q.empty()) {
        int n = q.size(); 
        for(int i = 0; i < n; i++) {
            curr = q.front();
            q.pop();
            if(i == n - 1)
                curr->next = NULL;
            else    
                curr->next = q.front();
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }
    }
    return root;
}
