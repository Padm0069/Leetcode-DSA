class Solution {
public:
    vector<int> nextSmallerRight(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
        
    }
    vector<int> nextSmallerLeft(vector<int> heights, int n){
        vector<int> res(n);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(i);
        }
        return res;
        
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> leftSmaller(n), rightSmaller(n);
        
        rightSmaller = nextSmallerRight(heights,n);
        leftSmaller = nextSmallerLeft(heights,n);

        
        int res = INT_MIN;
        
        for(int i=0; i<n; i++){
            int left = leftSmaller[i];
            int right = rightSmaller[i];
            int  w;
            
            if(left==-1) left = -1;
            if(right==-1) right = n;
            
            w = (right-1)-(left+1)+1;
            res = max(res,heights[i]*w);
        }
        
        
        return res;
    }
};