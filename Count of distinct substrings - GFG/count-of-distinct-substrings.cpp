//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

class Node{
   public:
   Node *links[26];
   
   bool containskey(char c)
   {
       return (links[c-'a']!=NULL);
   }
   
   Node * get(char c)
   {
       return links[c-'a'];
   }
   
   void put(char c , Node *node)
   {
       links[c-'a']=node;
   }
};

int countDistinctSubstring(string s)
{
   //Your code here
   Node *root =new Node();
   int n=s.size();

  int cnt =0;
  for( int i=0;i<n;i++)
  {
      Node *node =root;
      
      for( int j=i;j<n;j++)
      {
          if(!node->containskey(s[j]))
          {
                cnt++;
             node->put(s[j],new Node());
           
          }
          
          node=node->get(s[j]);
      }
  }
  return cnt+1;
}