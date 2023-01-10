//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int atMostK(string s, int k) {
    	//code here.
    	vector< long long int > f(26,0);
      long long int start=0,count=0,distinct=0;
      for(int i=0;i<s.size();i++){
          if(f[s[i]-'a']==0) distinct++;
          f[s[i]-'a']++;
          
          while(distinct>k ){
                   f[s[start]-'a']--;
                   if(f[s[start]-'a']==0)distinct--;
                   start++;
               }
           //count of substring     
          if(distinct <=k)count=count+i-start+1;
         }
       return count;
  }
    long long int substrCount (string s, int k) {
       return atMostK(s,k)- atMostK(s,k-1);
    }          
};
// idea  : 
// 1. calculate total substring having atmost k distinct characters.
// 2. calculate total substring having atmost k-1 distinct characters 
// 3.  no of substrings having exactly K distinct characters= substraction of point 2 from 1.

// Intuition: iterate over all the characters and create a window where there are k distinct characters. For every such window, calculate what is the largest index where k distinct characters will be still in the window (variable called index), and then the amount of substrings (with distinct characters) for that window will be
//  (i - start + 1), where start is the lower bound of the window and i is the upper bond
    


//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends