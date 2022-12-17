class Solution {
public:
	vector<int> next_largest(vector<int> &nums){
    
    int n = nums.size();
    stack<int> st;
    
    vector<int> ans(n,n);
    
    for(int i=0;i<nums.size();i++){
        
        while(st.size() and nums[st.top()]<=nums[i]){
            ans[st.top()]=i;
            st.pop();
        }
        
        st.push(i);
    }
    
    for(int i=0;i<ans.size();i++){
        int x = ans[i]-i-1;
        ans[i]=x;
    }
    
    return ans;
}

vector<int> next_smallest(vector<int> &nums){
    int n = nums.size();
    stack<int> st;
    
    vector<int> ans(n,n);
    
    for(int i=0;i<nums.size();i++){
        
        while(st.size() and nums[st.top()]>=nums[i]){
            ans[st.top()]=i;
            st.pop();
        }
        
        st.push(i);
    }
    
    for(int i=0;i<ans.size();i++){
        int x = ans[i]-i-1;
        ans[i]=x;
    }
    
    return ans;
}

vector<int> pre_largest(vector<int> &nums){
    int n = nums.size();
    stack<int> st;
    
    vector<int> ans(n,-1);
    
    for(int i=n-1;i>=0;i--){
        while(st.size() and nums[st.top()]<nums[i]){
            ans[st.top()]=i;
            st.pop();
        }
        
        st.push(i);
    }
    
    
    for(int i=0;i<nums.size();i++){
        int x = i-ans[i]-1;
        ans[i]=x;
    }
    
    return ans;
    
    
}

vector<int> pre_smallest(vector<int> &nums){
    
    int n = nums.size();
    stack<int> st;
    
    vector<int> ans(n,-1);
    
    
    for(int i=n-1;i>=0;i--){
        while(st.size() and nums[st.top()] > nums[i]){
            ans[st.top()]=i;
            st.pop();
        }
        
        st.push(i);
    }
    
    
    for(int i=0;i<nums.size();i++){
        int x = i-ans[i]-1;
        ans[i]=x;
        
    }
    
    return ans;
}



long long subArrayRanges(vector<int>& nums) {
    
    int n = nums.size();
    
    vector<int> pre_large = pre_largest(nums);
    vector<int> pre_small = pre_smallest(nums);
    
    vector<int> nxt_large = next_largest(nums);
    
    vector<int> nxt_small = next_smallest(nums);
    
    
    long long int sum=0;
    
    for(int i=0;i<n;i++){
        sum+= (nums[i]*1LL*(pre_large[i]+1))*(nxt_large[i]+1);
        sum-= (nums[i]*1LL*(pre_small[i]+1))*(nxt_small[i]+1);
    }
    
    return sum;
    
    
        
        
	}
};