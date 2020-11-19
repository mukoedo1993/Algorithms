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
   
    TreeNode* invertTree(TreeNode* root) {
     
        read_tree(root);
        
        
        return root;
    }
  private:
    void read_tree(TreeNode *rt){
        if(rt==nullptr)return;
        if(rt->left!=nullptr||rt->right!=nullptr){
           // TreeNode *nd1;
            nd1=rt->left;
            rt->left=rt->right;
            rt->right=nd1;
            read_tree(rt->left);
            read_tree(rt->right);
        }
    }
    TreeNode *nd1;
};
