vector<int> bottomView(Node *root) {
    if(!root)
        return {};
    
    queue<pair<Node*, int>> q; {node, horizontal distance from the root node}
    q.push({root, 0});
    map<int, int> m; // {horizontal distance from the root node}
    while(!q.empty()) {
        Node *front = q.front().first;
        int distance = q.front().second;
        q.pop();

        m[distance] = front->data;
        if(front->left)
            q.push({front->left, distance - 1});
        if(front->right)
            q.push({front->right, distance + 1});
    }
    vector<int> results;
    for(auto &p : m)
        results.push_back(p.second);
    
    return results;
}
