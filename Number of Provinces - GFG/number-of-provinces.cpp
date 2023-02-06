//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int index, vector<vector<int>> adj, int visited[], int V)
    {
        visited[index] = 1;
        
        for(int i = 0; i < V; i++)
        {
            if(adj[index][i] and visited[i] == 0)
            {
                visited[i] = 1;
                dfs(i, adj, visited, V);
            }
        }
    }
    
    int numProvinces(vector<vector<int>> adj, int V) {
        
        int visited[V] = {0};
        int comp = 0;
        
        for(int i = 0; i < V; i++)
        {
            if(!visited[i])
            {
                comp++;
                dfs(i, adj, visited, V);
            }
        }
        
        return comp;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends