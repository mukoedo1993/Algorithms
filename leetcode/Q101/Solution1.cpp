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
    bool isSymmetric(TreeNode* root) {
function<bool(TreeNode*,TreeNode*)> isMirror=[&isMirror](TreeNode* lhs, TreeNode *rhs)->bool{
    /*
    follow-up question:
    Why we cannot set the captured list as [isMirror](a.k.a. passed by value)?
    
    Because the isMirror is still incomplete( the right-hand-side is an implicit constructor).
    We cannot call an incomplete object directly, but by reference or pointer is OK.
    
    */
        if(!lhs)return (!rhs);
        if(!rhs)return false;
        return(lhs->val==rhs->val)&&
              isMirror(lhs->right,rhs->left)&&
              isMirror(rhs->right,lhs->left);
        
    };
   
      return isMirror(root,root);
    }
   

};
