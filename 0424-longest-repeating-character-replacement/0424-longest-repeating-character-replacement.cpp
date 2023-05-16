class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int start = 0;
        int maxCharCount = 0;
        int n = s.length();
        int result = 0;
        for(int end = 0; end < n; end++){
            counts[s[end]-'A']++;
            if(maxCharCount < counts[s[end]-'A']){
                maxCharCount = counts[s[end]-'A'];
            }
            while(end-start-maxCharCount+1 > k){
                counts[s[start]-'A']--;
                start++;
                // for(int i = 0; i < 26; i++){
                //     if(maxCharCount < counts[i]){
                //         maxCharCount = counts[i];
                //     }
                // }
            }
            result = max(result, end-start+1);
        }
        return result;
    }
};

// The problem says that we can make at most k changes to the string (any character can be replaced with any other character). So, let's say there were no constraints like the k. Given a string convert it to a string with all same characters with minimal changes. The answer to this is

// length of the entire string - number of times of the maximum occurring character in the string

// Given this, we can apply the at most k changes constraint and maintain a sliding window such that

// (length of substring - number of times of the maximum occurring character in the substring) <= k