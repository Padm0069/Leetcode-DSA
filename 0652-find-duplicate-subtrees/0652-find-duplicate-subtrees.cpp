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
    // declare an unordered map
    
    unordered_map<string, int> mp;
    
    // declare a res array
    
    vector<TreeNode*> res;
    
    // function for finding duplicate subtree
    
    string dfs(TreeNode* root)
    {
        // base case
        
        if(root == NULL)
        {
            return "";
        }
        
        // find the subtree for the curr node and store in str
        
        string str = "";
        
        str += to_string(root -> val);
        
        // provide delimeter
        
        str += "#";
        
        // call for left subtree
        
        string left = dfs(root -> left);
        
        str += left;
        
        // provide delimeter
        
        str += "#";
        
        // call for right subtree
        
        string right = dfs(root -> right);
        
        str += right;
        
        // increment the count of str
        
        mp[str]++;
        
        // if we found duplicate subtree then include the root into result
        
        if(mp[str] == 2)
        {
            res.push_back(root);
        }
        
        // return str
        
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // https://www.youtube.com/watch?v=nxHBg7hm0rs
        
        dfs(root);
        return res;
        
    }
};