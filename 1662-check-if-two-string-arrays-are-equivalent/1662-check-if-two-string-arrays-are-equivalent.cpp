class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a1="";
        string a2="";
        
        for(int i=0;i<word1.size();++i){
            a1=a1+word1[i];
        }
        
        for(int i=0;i<word2.size();++i){
            a2=a2+word2[i];
        }
        
        if(a1.size()!=a2.size()){
            return false;
        }
        
        for(int i=0;i<a1.size();++i){
            if(a1[i]!=a2[i]){
                return false;
            }
        }
        
        return true;
    }
};