class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        //w3e have to divide the levels into group of 3 or 2, every level.
//         If freq = 1, not possible, return -1
// If freq = 2, needs one 2-tasks
// If freq = 3, needs one 3-tasks
// If freq = 3k, freq = 3 * k, needs k batchs.
// If freq = 3k + 1, freq = 3 * (k - 1) + 2 + 2, needs k + 1 batchs.
// If freq = 3k + 2, freq = 3 * k + 2, needs k + 1 batchs.

// To summarize, needs (freq + 2) / 3 batch,
// return the sum of (freq + 2) / 3 if possible.
        
        unordered_map<int, int> count;
        int res = 0, freq1;
        for (int a: tasks)
            ++count[a];
        for (auto& it: count) {
            if (it.second == 1) return -1;
            res += (it.second + 2) / 3;
        }
        return res;
    }
};