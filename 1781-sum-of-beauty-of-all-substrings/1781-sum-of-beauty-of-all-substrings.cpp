class Solution {
public:
    int beautySum(string s) {
        int res = 0;
    for (auto i = 0; i < s.size(); ++i) {
        int cnt[26] = {}, max_f = 0, min_f = 0;
        for (auto j = i; j < s.size(); ++j) {
            int idx = s[j] - 'a';              //int value of the char
            max_f = max(max_f, ++cnt[idx]);     //stroring the count of char in count array
            if (min_f >= cnt[idx] - 1) {        //checking if min is changed or not
                min_f = cnt[idx];
                for (int k = 0; k < 26; ++k)
                    min_f = min(min_f, cnt[k] == 0 ? INT_MAX : cnt[k]);   //search count array to find new min
            }
            res += max_f - min_f;
        }
    }
    return res;
    }
};