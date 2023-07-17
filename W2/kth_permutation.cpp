class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact = 1;
        for(int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string result = "";
        k--;
        while(true) {
            result = result + to_string(numbers[k/ fact]);
            numbers.erase(numbers.begin() + k / fact);
            if(numbers.empty())
                break;
            k = k % fact;
            fact = fact / numbers.size();
        }
        return result;
    }
};
