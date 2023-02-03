//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        vector<vector<int>>dp(N+1,vector<int>(201,0));
        for(int i=0;i<=N;i++)
        {
            for(int curr=200;curr>=0;curr--)
            {
                if(i==0)
                    dp[i][curr] = curr==K;
                else
                {
                    int taken = dp[i-1][curr^arr[i-1]];
                    int nottake = dp[i-1][curr];
                     dp[i][curr] = taken+nottake;
                }
            }
        }
        return dp[N][0];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends