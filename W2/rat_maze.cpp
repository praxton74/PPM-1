class Solution{
    int row_dirs[4] = {1, 0, 0, -1};
    int col_dirs[4] = {0, -1, 1, 0};
    string dir = "DLRU";
    public:
    void dfs_helper(int sr, int sc, vector<vector<int>> &matrix, int n, string moves,
    vector<string> &results) {
        if(sr == n - 1 && sc == n - 1) {
            results.push_back(moves);
            return;
        } 
        if(sr < 0 || sc < 0 || sr >= n || sc >= n || matrix[sr][sc] == 0)
            return;
        matrix[sr][sc] = 0;
        
        for(int idx = 0; idx < 4; idx++) {
            dfs_helper(sr + row_dirs[idx], sc + col_dirs[idx], matrix, n, moves + dir[idx], results);
        }
        matrix[sr][sc] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &matrix, int n) {
        vector<string> results;
        if(matrix[0][0] == 1 && matrix[n - 1][n - 1] == 1)
            dfs_helper(0, 0, matrix, n, "", results);
        return results;
    }
};
