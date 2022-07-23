// 1.in the first pass I record counts of every character in a hashmap
// 2.in the second pass I locate the first character that appear less than k times in the string. this character is definitely not included in the result, and that separates the string into two parts.
// 3.keep doing this recursively and the maximum of the left/right part is the answer.

class Solution {
public:
    int longestSubstring(string s, int k) {
       int n = (int)s.length();
        unordered_map<char, int> count;
        for (char c : s) ++count[c];
        int mid = 0;
        while (mid < n && count[s[mid]] >= k) ++mid;
        if (mid == n) return n;
        int left = longestSubstring(s.substr(0, mid), k);
        while (mid < n && count[s[mid]] < k) ++mid;
        int right = longestSubstring(s.substr(mid), k);
        return max(left, right);
        
    }
};