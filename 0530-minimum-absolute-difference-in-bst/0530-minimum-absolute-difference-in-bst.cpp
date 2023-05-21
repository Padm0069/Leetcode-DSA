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
    int getMinimumDifference(TreeNode* root) {
        int min_num = INT_MAX;
        TreeNode* n = NULL;
        help(root, min_num, n);
        return min_num;
    }
    
    void help(TreeNode* n, int& min_num, TreeNode* &pre_n){
        if(n->left) help(n->left, min_num, pre_n);
        if(pre_n) min_num = min(min_num, abs(pre_n->val - n->val));
        pre_n = n;     //keeping track of prev nodes
        if(n->right) help(n->right, min_num, pre_n);
    }
};