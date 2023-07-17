static bool compare(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
int maxMeetings(int start[], int end[], int n) {
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++)
            arr[i] = make_pair(start[i], end[i]);
        
        sort(arr.begin(), arr.end(), compare);
        int count = 1; 
        int ft = arr[0].second; 
        
        for(int i = 1; i < n; i++) {
            if(arr[i].first > ft) {
                count++;
                ft = arr[i].second;
            }
        }
        return count;
    }
