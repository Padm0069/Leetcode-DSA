//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // take xor of all the numbers
        // the numbers occuring even number of times will reduce to zero
        long long int temp = 0;
        for(int i = 0; i < N; i++)
            temp = temp^Arr[i]; 
        // temp will now have the xor of two odd freq numbers(let them be a and b)
        // Get the rightmost set bit of temp (this bit is different in a and b)
        // Now divide the numbers into two groups 
        // one having this bit as 1 and others as 0
        // take xor of all these groups numbers
        // notice how as we have divided the groups based on that bit that is different in a and b
        // now each group will only have one odd freq number and rest numbers will reduce to
        // zero due to their even freq thus giving us the two odd freq numbers seperately
        long long num1 = 0,num2 = 0,rightmost_setbit = temp & ~(temp-1);
        for(int i=0;i<N;i++)
        {
            if(Arr[i]&rightmost_setbit)
                num1 ^= Arr[i];
            else
                num2 ^= Arr[i];
        }
        vector<long long int> ans({num1,num2});
        sort(ans.rbegin(),ans.rend());
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends