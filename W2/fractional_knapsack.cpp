class Solution
{
    public:
    static bool compare(Item &a, Item &b) {
        return ((double)a.value / a.weight) > ((double)b.value / b.weight);
    }
    
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, compare);
        int cur_w = 0;
        double max_val = 0;
        for(int i = 0; i < n; i++) {
            if(cur_w + arr[i].weight <= W) {
                cur_w += arr[i].weight;
                max_val += arr[i].value;
            }
            else {
                int remaining_w = W - cur_w;
                max_val += arr[i].value * ((double)remaining_w / arr[i].weight);
                break;
            }
        }
        return max_val;
    }
};
