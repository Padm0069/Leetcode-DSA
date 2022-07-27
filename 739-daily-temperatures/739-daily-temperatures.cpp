class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
         // support variables
        int len = temperatures.size(), pos = 0, s[250];
        s[pos] = len - 1;
        vector<int> res(len);
        // looping from right to left, starting from the penultimate element
        for (int i = len - 2, n; i >=0; --i) {
            n = temperatures[i];
            // removing reducing pos as long as we find smaller elements
            while (pos >= 0 && n >= temperatures[s[pos]]) pos--;
            // // if we still have something in the array, we update res
            if (pos > -1) res[i] = s[pos] - i;
            // updating the array
            s[++pos] = i;
        }
        return res;
    }
};