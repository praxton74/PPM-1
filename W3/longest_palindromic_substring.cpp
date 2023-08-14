

class Solution {
public:
    void expandBothSides(string &s, int left, int right, int &start_idx, int &max_len, const int n) {
        while(left >= 0 && right < n && s[left] == s[right]) {
            if(right - left + 1 > max_len) {
                start_idx = left;
                max_len = right - left + 1;
            }
            left--;
            right++;
        }
    }
    
    string longestPalindrome(string &s) {
        const int n = (int)s.size();
        int start_idx = 0; 
        int max_len = 1; 
        int left, right;
        
        for(int i = 1; i < n; i++) {
            left = i - 1;
            right = i;
            expandBothSides(s, left, right, start_idx, max_len, n);
            
            left = i - 1;
            right = i + 1;
            expandBothSides(s, left, right, start_idx, max_len, n);
        }
        return s.substr(start_idx, max_len);
    }
};
