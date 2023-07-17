class Solution{   
public:
    int countSmallerThanEqualToMid(vector<int> &row, int n, int key) {
        int start = 0, end = n - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(row[mid] <= key)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return start;
    }

    int median(vector<vector<int>> &matrix, int r, int c){
        int start = 0, end = 2000;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            int count = 0; 
            for(int i = 0; i < r; i++) {
                count += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());
            }
            if(count <= (r * c) / 2)
                start = mid + 1;
            else 
                end = mid - 1;
        }
        return start;
    }
};
