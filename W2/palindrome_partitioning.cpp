class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    
    void partition_helper(string &s, int idx, vector<string> &path, vector<vector<string>> &results) {
        if(idx == s.size()) {
            results.push_back(path);
            return;
        }
        for(int i = idx; s[i]; i++) {
            if(isPalindrome(s, idx, i)) {
                path.push_back(s.substr(idx, i - idx + 1));
                partition_helper(s, i + 1, path, results);
                path.pop_back();   
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> path;
        partition_helper(s, 0, path, results);
        return results;
    }
};
