class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>ans;
        priority_queue<pair<int , int>> p;
        for(int i=0;i<arr.size();i++){
            p.push({abs(arr[i]-x) , arr[i]});
            if(p.size()>k){
                p.pop();
            }
        }
        while(p.size()>0){
            ans.push_back(p.top().second);
            p.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};