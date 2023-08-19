class Solution {
public:
    int f(int idx,int m,vector<int>&piles,int flag,vector<vector<vector<int>>>&dp){
        if(idx>=piles.size()){
            return 0;
        }
        int ans=0;
        
        if(dp[flag][idx][m]!=-1){
            return dp[flag][idx][m]; 
        }
        
        if(flag==1){
            ans=-1;
        }
        else{
            ans=INT_MAX; 
        }
        int sum=0;
        for(int x=1;x<=2*m;++x){
            if(idx+x>piles.size()){
                break; //out of bound
            }
            sum+=piles[idx+x-1]; 
            
            if(flag){
                
                ans=max(ans,sum+f(x+idx,max(m,x),piles,!flag,dp));
            }
            else{
                ans=min(ans,f(x+idx,max(m,x),piles,!flag,dp)); 
                
                
            }
        }
        
        return dp[flag][idx][m]=ans;
        
    }
    
    
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return f(0,1,piles,1,dp);
        
    }
};