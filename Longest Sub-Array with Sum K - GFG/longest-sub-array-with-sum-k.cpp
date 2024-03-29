//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        int ln=0,sum=0;
        map<int,int>m;
        for(int i=0;i<N;i++)
        {
            sum+=A[i];
            if(sum==K)ln=max(i+1,ln);
            if(m.find(sum)==m.end())m[sum]=i;
            if(m.find(sum-K)!=m.end())ln=max(ln,i-m[sum-K]);
        }
        return ln;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends