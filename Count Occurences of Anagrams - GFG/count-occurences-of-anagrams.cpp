// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    // code here
	unordered_map<char, int> mp;
    int ans = 0;
    
    //storing the occ. of string p in the map
    for (auto &x : pat){
        mp[x]++;
    }

    int count = mp.size();
    int k = pat.size();
    int i=0, j=0;

    while (j < txt.size()){
        //calculation part
        if (mp.find(txt[j]) != mp.end()){
            mp[txt[j]]--;
            if (mp[txt[j]] == 0){
                count--;
            }
        }

        //window length not achived yet
        if (j-i+1 < k){
            j++;
        }

        //window length achived, find ans and slide the window
        else if (j-i+1 == k){
            //finding the ans
            if (count == 0){
                ans++;
            }
            if (mp.find(txt[i]) != mp.end()){
                mp[txt[i]]++;
                if (mp[txt[i]] == 1){
                    count++;
                }
            }

            //slide the window
            i++;
            j++;
        }
    }
    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends