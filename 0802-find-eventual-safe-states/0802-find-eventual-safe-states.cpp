class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //first we reverse thhe edges of the graph.
        
        //yopo sort i.e take the nodes with indegree 0 and then take the neighbors and reduce thier indegree and take it again.
        int n = graph.size();
        vector<vector<int>> g(n);
        vector<int> indgree(n, 0);
        queue<int> q;
        
        for(int i = 0; i < n; i++)
        {
            for(auto j: graph[i]){
                g[j].push_back(i);
                indgree[i]++;
            }
        }
        for(int i =0 ; i < n; i++)
            if(indgree[i] == 0)q.push(i);
        
        vector<int> res;
        while(!q.empty())
        {
            int k = q.front();
            res.push_back(k);
            q.pop();
            for(auto i: g[k])
            {
                indgree[i]--;
                if(indgree[i] == 0)q.push(i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};