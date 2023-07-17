class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int start = 0, end = rows * cols - 1;
        int mid, r, c;
        while(start <= end) {
            mid = start + (end - start) / 2;
            r = mid / cols;
            c = mid % cols;
            if(matrix[r][c] == target)
                return true;
            if(target < matrix[r][c])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};
