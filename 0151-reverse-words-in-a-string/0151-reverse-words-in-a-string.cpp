class Solution {
public:
    string reverseWords(string s) {
    //     stack<string> st;
    // string str = "";
    
    // for (int i = 0; i < s.length(); i++) {
    //     if (s[i] == ' ') {
    //         if (!str.empty()) { // avoid pushing empty strings
    //             st.push(str);
    //             str = "";
    //         }
    //     } else {
    //         str += s[i];
    //     }
    // }
    // if (!str.empty()) st.push(str); // push last word
    
    // string ans = "";
    // while (!st.empty()) {
    //     ans += st.top();
    //     st.pop();
    //     if (!st.empty()) ans += " "; // add space only if not last word
    // }
    // return ans;
        int n = s.length();
        string result = "";
        int i = n - 1;

        while (i >= 0) {
            if (s[i] == ' ') {
                i--;
                continue;
            }
            int j = i;
            while (j >= 0 && s[j] != ' ') j--;

            if (!result.empty()) result += " ";
            result += s.substr(j + 1, i - j);

            i = j - 1;
        }
        return result;

    }
};
