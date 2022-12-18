class Solution {
public:
    
    int mah(vector<int> arr, int n){
        
        vector<int> nsl;
        
        stack<int> st;
        
        for(int i = 0 ; i<n ; i++){
            if(st.empty()){
                nsl.push_back(-1);
            }
            else if(arr[st.top()] < arr[i]){
                nsl.push_back(st.top());
            }
            else if(arr[st.top()] >= arr[i]){
                while(st.size()>0 && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsl.push_back(-1);
                }else{
                    nsl.push_back(st.top());
                }
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        vector<int> nsr;
        
        for(int i = n-1 ; i>=0 ; i--){
            
            if(st.empty()){
                nsr.push_back(n);
            }
            else if(arr[st.top()] < arr[i]){
                nsr.push_back(st.top());
            }
            else if(arr[st.top()] >= arr[i]){
                while(st.size()>0 && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    nsr.push_back(n);
                }else{
                    nsr.push_back(st.top());
                }
            }
            st.push(i);
        }
        reverse(nsr.begin(),nsr.end());
        
        int mahAns = INT_MIN;
        
        for(int i = 0 ; i<n ; i++){
            int ans =arr[i]*( (i-nsl[i] - 1) + (nsr[i]-i) );
            mahAns = max(mahAns,ans);
        }
        
        return mahAns;
 }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int cols = matrix[0].size();
        int rows = matrix.size();
        
        // cout<<rows<<" "<<cols<<endl;
        
        vector<int> arr(cols,0);
    
        int maxArea = -1;

        for(int i = 0 ; i<rows ; i++){

            for(int j = 0 ; j<cols ; j++){
                if((matrix[i][j] - '0') !=0){
                    arr[j]+=1;
                }else{ //we can't include a 0 inside a rectangle and thus we have to 
				       // discard that column for that particular (m x n) calculation.
                    arr[j] = 0;
                }
            }

            maxArea = max(maxArea, mah(arr,cols)); 
			//keep adding rows and reserving the max area counted till now 
        }

        return maxArea;
    }
};
// Time Complexity : O(n * (m + n) )
// Space Complexity : O(n + n) [dp array + stack to find largest rectangle]