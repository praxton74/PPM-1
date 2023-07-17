class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        
        int max_len = 1;
        int visited[256] = {0};
        int left = 0, right = 0, n = s.size();
        while(right < n) {
            visited[s[right]]++;
            while(visited[s[right]] > 1) {
                visited[s[left]]--;
                left++;
            }
            max_len = max(max_len, right - left + 1);
            right++;
        }
        return max_len;
    }
};
