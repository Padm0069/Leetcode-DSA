//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void helper(string str, int i, int prev, int n){
        if(i==n){
           cout << str << " ";
           return;
        }
        
        if(prev==-1){
            helper(str+'0',i+1,0,n);
            helper(str+'1',i+1,1,n);
        }
        else if(prev==0){
            helper(str+'0',i+1,0,n);
            helper(str+'1',i+1,1,n);
        }
        else {
             helper(str+'0',i+1,0,n);
        }
    }
    
    void generateBinaryStrings(int& num){
        int i = 0;
        int n = num;
        helper("",i,-1,n);
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        // cout << setprecision(9) << obj.switchCase(choice,vec) << endl;
        obj.generateBinaryStrings(n);
        cout << endl;
        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends