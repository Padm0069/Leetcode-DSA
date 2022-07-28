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
private:
    int calculateSum(TreeNode* root, long long targetSum)
    {
        if(!root)
            return 0;
                
        return (targetSum == root->val) + calculateSum(root->left, targetSum-root->val) + calculateSum(root->right, targetSum-root->val);
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
                
        if(!root)
            return 0;
        
        return calculateSum(root, (long long)targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
        
    }
};