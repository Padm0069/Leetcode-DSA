class Solution {
public:
    string removeOuterParentheses(string s) {
// When we meet outermost '(', the count will be 0, so we post increment the count to ignore that '('.
// When we meet outermost ')', the count will be 1, so we pre decrement the count to ignore that ')'.
        
        int count = 0;
        string str;
        for (char c : s) {
            if (c == '(') {
                if (count++) {
                    str += '(';
                }
            } else {
                if (--count) {
                    str += ')';
                }
            }
        }
        return str;
    }
};