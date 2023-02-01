//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        vector<int>ans;
        stack<int>st;
        
        st.push(a[n-1]);
        
        for(int i = n-2;i>=0;i--){
            if(a[i]>=st.top()){      //change in maxi suffix element
                st.push(a[i]);
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }    
        return ans;
        
    }
    
    //works on the principle of suffix max element i.e find max elements from right to left and if there 
    //is a change take it into stack(to maintain array order) ans output it in ans.
};

//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends