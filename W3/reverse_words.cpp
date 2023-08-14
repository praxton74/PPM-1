class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(word.empty()) {
                while(s[i] == ' ')
                    i++;
            }
            if(s[i] != ' ')
                word += s[i];
            if(s[i] == ' ' || i == n - 1) {
                if(!word.empty())
                    st.push(word);
                word.clear();
            }
        }
        word.clear();
        while(!st.empty()) {
            word += st.top();
            st.pop();
            word += " ";
        }
        word.pop_back();
        return word;
    }
};
