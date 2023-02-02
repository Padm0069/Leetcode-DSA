//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        unordered_map<int,int>mp;
        int csum=0;
        int fans=0;
        for(int i=0;i<n;i++){
            csum+=A[i];
            if(csum==0)
            {
                fans=max(fans,i+1);
            }
            else{
                if(mp.find(csum)!=mp.end())
                {
                    fans=max(fans,i-mp[csum]);       //kind of a prefix sum logic
                }
                else{
                    mp[csum]=i;
                }
            }
        }
        return fans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends