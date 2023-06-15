/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
       if(!root) return NULL;
        
        queue<TreeNode*>q;
        q.push(root);
        int level =0;
        int ans = INT_MIN;
        int ans_level;
        
        while(!q.empty()){
            level++;
            int size = q.size();
            int sum = 0;
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                sum+=node->val;
            }
            if(sum>ans){
                ans_level = level;
                ans = sum;
            }
            
             
            
        }
        
        return ans_level;
    }
};