class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        std::vector<int> parent(accounts.size(), 0);
        std::unordered_map<std::string, int> email_id;
        
        // We gather all the e-mails and the group in whick thet belong
        // We make groups for the case that one e-mail has multiple accounts
        for (int i = 0; i < accounts.size(); i++) {
            // Initialize the parent vector
            parent[i] = i;
            for (int j = 1; j < accounts[i].size(); j++) {
                // If this e-mail has been found again then union-find in order to 
                // add under the same group the current e-mail and the already stored
                // e-mail
                if (email_id.find(accounts[i][j]) != email_id.end()) {
                    int f1 = find(parent, i);
                    int f2 = find(parent, email_id[accounts[i][j]]);
                    // Union
                    parent[f1] = f2;
                } else {
                    // If this e-mail is found for the first time then add it to the map
                    email_id[accounts[i][j]] = i;
                }
            }
        }
        // We make a new map in order to store for every group the e-mails it contains
        std::unordered_map<int, std::vector<std::string>> mres;
        for (auto it : email_id) {
            int f = find(parent, it.second);
            mres[f].push_back(it.first);
        }
        
        // In the previous (mres) map we have our answer but we must give the proper structure
        // We add the name of the account (we retieve it from the initial vector since we have
        // the number of the group) and we sort the e-mails.
        std::vector<std::vector<std::string>> res;
        for (auto it : mres) {
            std::sort(it.second.begin(), it.second.end());
            std::vector<std::string> tmp = {accounts[it.first][0]};
            for (auto i : it.second) tmp.push_back(i);
            res.push_back(tmp);
        }
        return res;
    }
    int find(std::vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }
};