//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{

    vector<int> parent,rank;

    

    public:

    DisjointSet(int n){

        parent.resize(n+1);

        rank.resize(n+1);

        

        for(int i=0;i<=n;i++){

            parent[i]=i;

            rank[i]=0;

        }

    }

    

    int findparent(int u){

        if(u==parent[u])return u;

        

        return parent[u] = findparent(parent[u]);

    }

    

    void union_by_rank(int u,int v){

        int paru = findparent(u);

        int parv = findparent(v);

        

        if(paru==parv)return;

        

        if(rank[paru]<rank[parv]){

            parent[paru]=parv;

        }

        else if(rank[parv]<rank[paru]){

            parent[parv]=paru;

        }

        else{

            parent[parv]=paru;

            rank[paru]++;

        }

    }

};
class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
         int maxrow=0, maxcol=0;

        for(auto it:stones){       //to find the last stone in row and col gives us dimension

            maxrow = max(maxrow , it[0]);

            maxcol = max(maxcol , it[1]);

        }

        

        DisjointSet ds(maxrow+maxcol +1);

        unordered_map<int,int> stonenodes;

        

        for(auto it:stones){

            int noderow = it[0];

            int nodecol = it[1] + maxrow + 1;

            //cout<<noderow<<" "<<nodecol<<endl;

            ds.union_by_rank(noderow, nodecol);

            stonenodes[noderow] = 1;

            stonenodes[nodecol] = 1;

        }

        

        int component=0;

        

        for(auto it:stonenodes){

            //cout<<it.first<<" ";

            if(ds.findparent(it.first)==it.first){

                component++;

            }

        }

        

        //cout<<endl;

        return n - component;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends