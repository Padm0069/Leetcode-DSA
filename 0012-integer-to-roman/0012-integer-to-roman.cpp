class Solution {
public:
    string intToRoman(int num) {
       vector<string>sym{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","III","I"};
        vector<int>val{1000,900,500,400,100,90,50,40,10,9,5,4,3,1};
        
        unordered_map<int,string>mp;
        
        int n=val.size();
        for(int i=0;i<n;++i){
            mp[val[i]]=sym[i];
        }
        int k=0;
        string ans="";
        while(num>0){
            while(val[k]<=num){
                num=num-val[k];
                ans=ans+mp[val[k]];
            }
            k++;
        }
        
        return ans; 
    }
};