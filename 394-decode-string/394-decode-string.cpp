
// 1. Every time we meet a '[', we treat it as a subproblem so call our recursive function to get the content in that '[' and ']'. After that, repeat that content for 'num' times.
// 2. Every time we meet a ']', we know a subproblem finished and just return the 'word' we got in this subproblem.
// 3. Please notice that the 'pos' is passed by reference, use it to record the position of the original string we are looking at.

class Solution {
public:
    string decodeString(string s) {
        int pos = 0;
        return helper(pos,s);
    }
    
    string helper(int& pos, string s) {
        int num=0;
        string word = "";
        for(;pos<s.size(); pos++) {
            char cur = s[pos];
            if(cur == '[') {
                string curStr = helper(++pos, s);
                for(;num>0;num--) word += curStr;
            } else if (cur >= '0' && cur <='9') {
                num = num*10 + cur - '0';
            } else if (cur == ']') {
                return word;
            } else {    // Normal characters
                word += cur;
            }
        }
        return word;
    }
};