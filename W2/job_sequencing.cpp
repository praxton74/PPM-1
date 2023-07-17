    static bool compare(Job &a, Job &b) {
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr + n, compare);
        int result[n];
        int slot[n] = {0};
        for(int i = 0; i < n; i++) {
            for(int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
                if(slot[j] == 0) {
                    result[j] = i; 
                    slot[j] = 1; 
                    break;
                }
            }
        }
        int jobs = 0, profit = 0;
        for(int i = 0; i < n; i++) {
            if(slot[i] == 1) {
                jobs++; 
                profit += arr[result[i]].profit;
            }
        }
        return {jobs, profit};
    } 
};
