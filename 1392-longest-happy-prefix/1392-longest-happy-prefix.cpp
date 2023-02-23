class Solution {
public:
    vector<int> lps(string& word)
    {
        //uses KMP Algorithm
        vector<int> lp(word.length(), 0);
        
        int index = 0;
        for(int i = 1; i < word.length();)
        {
            if(word[i] == word[index])
            {
                index++;
                lp[i] = index;
                i++;
            }
            else
            {
                if(index != 0)
                    index = lp[index-1];
                else
                    i++;     //no match
            }
        }
        
        return lp;
    }
    
    string longestPrefix(string s) {
        vector<int> lp = lps(s);
        
        return s.substr(0, lp.back());       //substring starting with 0 and lp lenght
    }
};