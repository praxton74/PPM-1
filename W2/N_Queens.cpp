bool isQueenSafe(vector<string> &chess, int row, int col) {
    for(int i = row - 1, j = col; i >= 0; i--) {
        if(chess[i][j] == 'Q')
            return false;
    }
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(chess[i][j] == 'Q')
            return false;
    }
    for(int i = row - 1, j = col + 1; i >= 0 && j < chess[0].size(); i--, j++) {
        if(chess[i][j] == 'Q')
            return false;
    }
    return true;
}
void printNQueens(vector<string> &chess, vector<vector<string>> &results, int row, int n) {
    if(row == n) {
        results.push_back(chess);
        return;
    }
    for(int col = 0; col < n; col++) {
        if(isQueenSafe(chess, row, col)) {
            chess[row][col] = 'Q';
            printNQueens(chess, results, row + 1, n);
            chess[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> results;
    vector<string> chess(n, string(n, '.'));
    printNQueens(chess, results, 0, n);
    return results;
}