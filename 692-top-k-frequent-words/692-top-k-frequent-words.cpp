class Solution {
public:
    
struct greater1{
  bool operator()(pair<int, string> &a, pair<int, string> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
    #define pis pair<int, string>
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for(auto &e : words) m[e]++;
        priority_queue<pis, vector<pis>, greater1> minh;
        for(auto &e : m){
            minh.push({e.second, e.first});
            if(minh.size() > k) minh.pop();
        }
      vector<string> ans;
        while(!minh.empty()){
            ans.insert(ans.begin(),minh.top().second);
            minh.pop();
        }
        return ans;
    }
};