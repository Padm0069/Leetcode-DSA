class Solution {
public:
    void dfs(vector<int> adj[],int node,vector<bool> &vis,int &c)
    {
        c++;
        vis[node] = true;;
        
        for(auto anode: adj[node])
            if(!vis[anode]) dfs(adj,anode,vis,c);       
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) 
    {
        vector<int> adj[n];
        long long int ans=0,total=0;
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        vector<bool> vis(n,0);
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int c=0;
                dfs(adj,i,vis,c);       
                ans += total*c;           
                total+=c;
            }
        }
      
        return ans;
    }
};