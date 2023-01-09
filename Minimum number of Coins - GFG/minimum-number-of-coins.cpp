//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        // code here
        vector<int> deno = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        vector<int> ans;
        
        for(int i = 0; i < deno.size(); i++) {
            
            while(N >= deno[i]) {
                N -= deno[i];
                ans.push_back(deno[i]);
            }
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends