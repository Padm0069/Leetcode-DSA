class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &f:flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        using arr = pair<int,pair<int,int>>;
        priority_queue<arr, vector<arr>, greater<arr>> pq;
        
        vector<int>dist(n,INT_MAX);
        pq.push({0,{src,0}});
        dist[src] = 0;
        while(!pq.empty()){
            auto it=pq.top();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            
            pq.pop();
            
            if(stops>k){
                continue;
            }
            
            for(auto it:adj[node]){
                if(dis+it.second<dist[it.first]){
                    dist[it.first]=dis+it.second;
                    pq.push({{stops+1},{it.first,dis+it.second}});
                }
            }
            
            
        }
        
        if(dist[dst]==INT_MAX){
            return -1;
        }
        
        return dist[dst];
    }
};