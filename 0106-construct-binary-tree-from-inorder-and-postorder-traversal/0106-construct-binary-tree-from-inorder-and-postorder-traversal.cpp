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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size())
            return NULL;
        map<int,int> hm;
        for (int i=0;i<inorder.size();++i)
            hm[inorder[i]] = i;
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, 
                              postorder.size()-1,hm);
    }
    TreeNode* buildTreePostIn(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, 
                                     map<int,int> &hm){
        if (ps>pe || is>ie) return NULL;
        TreeNode* root = new TreeNode(postorder[pe]);
        int ri = hm[postorder[pe]];
        root ->left = buildTreePostIn(inorder, is, ri-1, postorder, ps, ps+ri-is-1, hm);
        root ->right = buildTreePostIn(inorder,ri+1, ie, postorder, ps+ri-is, pe-1, hm);
        return root;
    }
};