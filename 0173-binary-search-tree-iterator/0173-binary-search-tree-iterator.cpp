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
class BSTIterator {
 
public:
    stack<TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        //push all the left nodes in the stack    
        while (root != NULL){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode *currNode = st.top();
        st.pop();
        if (currNode->right != NULL){
            TreeNode *temp = currNode->right;
            while (temp != NULL){
                st.push(temp);
                temp = temp->left;
            }
        }
        return currNode->val;
    }
    
    bool hasNext() {
        if (!st.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */