class Solution {
public:
    #define WHITE 0
#define RED 1
#define BLUE 2
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1); // adjacency list for undirected graph
        vector<int> color(n + 1, WHITE); // color of each vertex in graph, initially WHITE
        vector<bool> explored(n + 1, false); // to check if each vertex has been explored exactly once
        
        // create adjacency list from given edges
        for (auto &edge: dislikes)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // print adjacency list (comment out before submitting)
        // for (int i = 0; i <= N; ++i)
        // {
        //     cout << "adj[" << i << "]: ";
        //     for (int j = 0; j < adj[i].size(); ++j)
        //     {
        //         cout << adj[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        
        // queue to perform BFS over each connected component in the graph
        // while performing BFS, we check if we encounter any conflicts while
        // coloring the vertices of the graph
        // conflicts indicate that bi-partition is not possible
        queue<int> q;
        
        for (int i = 1; i <= n; ++i)
        {
            if (!explored[i])
            {
                // this component has not been colored yet
				// we color the first vertex RED and push it into the queue
                color[i] = RED;
                q.push(i);
                
                // perform BFS from vertex i
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    
                    // check if u is already explored 
                    if (explored[u])
                    {
                        continue;
                    }
                    
                    explored[u] = true;
                    
                    // for each neighbor of u, execute this loop
                    for (auto v: adj[u])
                    {
                        // v is u's neighboring vertex
                        
                        // checking if there's any conflict in coloring
                        if (color[v] == color[u])
                        {
							// conflict edge found, so we return false 
							// as bi-partition will not be possible
                            return false;
                        }
                        
                        // we color v with the opposite color of u
                        if (color[u] == RED)
                        {
                            color[v] = BLUE;
                        }
                        else 
                        {
                            color[v] = RED;
                        }
                        
                        q.push(v);
                    }
                }
            }
        }
        
        // if no conflicts encountered then graph must be bipartite
        // so we return true
        
        return true;
    }
};