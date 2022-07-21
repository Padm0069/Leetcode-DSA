class Solution {
public:
    string frequencySort(string s) {
       unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;
        string ans;
        
        for(char c : s)
            m[c]++;
        for(auto it : m)
            pq.push({it.second, it.first}); // will be in descending order of freq
        
        while(!pq.empty()) {
            pair<int, char> curr = pq.top();
            pq.pop();
            int freq = curr.first;
            while(freq > 0) {
                ans.push_back(curr.second);
                freq--;
            }
        }
        
        return ans;
    }
};