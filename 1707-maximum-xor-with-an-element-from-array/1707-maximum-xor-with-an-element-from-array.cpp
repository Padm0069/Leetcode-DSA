struct Node{
    Node *links[2];
    bool contain(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node *node){
        links[bit]=node;
    }
    Node *get(int bit){
        return links[bit];
    }
};
class Trie{
    private: Node *root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int &num){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->contain(bit)){
                node->put(bit,new Node());
            }node=node->get(bit);
        }
    }
    int getMax(int &num){
        Node *node=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->contain(1-bit)){
                maxi=maxi|(1<<i);
                node=node->get(1-bit);
            }
            else node=node->get(bit);
        }
        return maxi;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& qu) {
        Trie trie;
        int i;
        vector<vector<int>>arr;
        for(i=0;i<qu.size();i++){
            int x=qu[i][0];
            int lim=qu[i][1];
            arr.push_back({lim,x,i});
        }
        vector<int>ans(qu.size());
        int n=nums.size();
        sort(nums.begin(),nums.end());
        sort(arr.begin(),arr.end());
        int ind=0;
        for(i=0;i<qu.size();i++){
            int lim=arr[i][0];
            int x=arr[i][1];
            int qind=arr[i][2];
            while(ind<n&&nums[ind]<=lim){
                trie.insert(nums[ind]);
                ind++;
            }
            if(ind==0) ans[qind]=-1;
            else ans[qind]=trie.getMax(x);
        }
        return ans;
    }
};