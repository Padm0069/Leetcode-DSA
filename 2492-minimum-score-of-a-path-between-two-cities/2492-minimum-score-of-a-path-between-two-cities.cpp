class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int k=roads.size();
        vector<vector<pair<int,int>>>dfs(n+1);
        for(int i=0;i<k;i++)
        {
            dfs[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            dfs[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<int>vis(n+2,0);

        queue<vector<int>>q;
        q.push({n,INT_MAX});
        int mini=INT_MAX;

        while(!q.empty())
        {
            auto tp=q.front();
            q.pop();
            mini=min(mini,tp[1]);
            vis[tp[0]]=1; 
            for(auto ele:dfs[tp[0]])
            {
                if(!vis[ele.first])
                {
                    q.push({ele.first,ele.second});
                }
            }
        }
        return mini;
    }
};