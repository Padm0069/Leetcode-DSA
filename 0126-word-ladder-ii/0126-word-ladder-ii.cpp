class Solution {
public:
    vector<string> ws;
    vector<int> dis;
    unordered_map<string, int> mp;
    int n;
    vector<vector<string>> ans;
    void dfs(int i, int d, vector<string>& p) {
        auto& w = ws[i];
        if (d == 0) {
            p.push_back(w);
            ans.emplace_back(p);
            p.pop_back();
            return;
        }
        d--;
        p.push_back(w);
        for (int j = 0; j < w.size(); j++) {
            char c = w[j];
            for (char x = 'a'; x <= 'z'; x++) {
                if (c == x) continue;
                w[j] = x;
                if (mp.count(w) == 0) continue;
                int y = mp[w];
                if (dis[y] != d) continue;    
                dfs(y, d, p);
                
            }
            w[j] =c ;
        }
        p.pop_back();
    }
    vector<vector<string>> findLadders(string b, string e, vector<string>& wordList) {
        ws = std::move(wordList); 
        n = ws.size();
        dis = vector<int>(n + 1, INT_MAX);
        
        for (int i = 0; i < n; i++) mp[ws[i]] = i;
        if (mp.count(b) == 0) {
            ws.push_back(b);
            mp[b] = ws.size() - 1;
        }
        
        if (mp.count(e) == 0) return ans; 
        int ml = INT_MAX;
        deque<int> q;
        q.push_back(mp[e]);
        dis[mp[e]] = 0;
        
        while (!q.empty()) {
            int i = q.front();
            q.pop_front();
            auto& w = ws[i];
            int d = dis[i];
            //cout << i << "," << w << "," << d << endl;
            
            for (int j = 0; j < w.size(); j++) {
                char c = w[j];
                for (char x = 'a'; x <= 'z'; x++) {
                    if (c == x) continue;
                    w[j] = x;
                    if (mp.count(w) == 0) continue;
                    int y = mp[w];
                    if (dis[y] != INT_MAX) continue;
                    dis[y] = d + 1;
                    q.push_back(y);
                }
                w[j] =c ;
            }
        }
        //cout << dis[mp[b]] << endl;
        int d = dis[mp[b]];
        if (d == INT_MAX) return ans;
        vector<string> path;
        dfs(mp[b], d, path);
        
        return ans;
    }
};