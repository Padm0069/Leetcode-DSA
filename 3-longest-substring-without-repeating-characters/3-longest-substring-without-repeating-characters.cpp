class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int n=s.size();
        if(n==0)return 0;
        unordered_map<char,int>m;
        int i=0,j=0,ans=INT_MIN;
        
        while(j<n)
        {
            m[s[j]]++;
            
            if(m.size()<j-i+1)
            {
                while(m.size()<j-i+1 and m.size()>0)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                        m.erase(s[i]);
                    
                    i++;
                }
                j++;
            }
            else if(m.size()==j-i+1)
            {
                ans=max(ans,j-i+1);
                j++;
            }
        }
        
        return ans;
    }
};