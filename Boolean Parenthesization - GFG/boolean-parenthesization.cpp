//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

#define ll long long 
int mod = 1003;
    int countWays(int N, string S){
        // code here
        
    vector<vector<vector<ll>>> dp(N, vector<vector<ll>> (N, vector<ll> (2, 0)));
    
    for(int i=0; i<N; i++){
        dp[i][i][1] = S[i] == 'T';
        dp[i][i][0] = S[i] == 'F';
    }
    
    for(int i=N-1; i>=0; i--){
        for(int j=i+1; j<N; j++){
            for(int isTrue=0; isTrue <=1; isTrue++){
                ll ways=0;
                for(int ind =i+1; ind <= j-1; ind=ind+2){
                    ll lT = dp[i][ind-1][1];
                    ll lF = dp[i][ind-1][0];
                    ll rT = dp[ind+1][j][1];
                    ll rF = dp[ind+1][j][0];
                    if(S[ind] == '&'){
                        if(isTrue) ways = (ways + (lT * rT)%mod)%mod;
                        else ways = (ways + (lT*rF)%mod + (lF*rF)%mod + (lF*rT)%mod)%mod;
                    }
                    else if(S[ind] == '|'){
                        if(isTrue) ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else ways = (ways + (lF*rF)%mod)%mod;
                    }
                    else{
                        if(isTrue) ways = (ways + (lT*rF)%mod + (lF*rT)%mod)%mod;
                        else ways = (ways + (lT*rT)%mod + (lF*rF)%mod)%mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    
    return dp[0][N-1][1];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends