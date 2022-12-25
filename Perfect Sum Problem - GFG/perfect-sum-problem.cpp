//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	 public:

   int m = 1e9 + 7;

 int find(int i,int arr[], int sum, vector<vector<int> >&dp){

         if(i==0) {

            if (sum==0 and arr[0]==0)   return 2;

               if(sum==0 or sum==arr[0])  return 1;

                return 0 ;

         }

         if(dp[i][sum]!=-1) return (dp[i][sum])%m;

    int take = 0;

     if(arr[i]<= sum) take =  find( i-1,arr, sum-arr[i], dp); 

     int nottake = find( i-1,arr, sum, dp); 

     return dp[i][sum]= ((take%m) + (nottake%m));

 }

 int perfectSum(int arr[], int n, int sum)

 {

        // Your code goes here

        vector<vector<int> >dp(n+1, vector<int>(sum+1, -1));

        return find(n-1, arr, sum, dp)%m;

 }
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends