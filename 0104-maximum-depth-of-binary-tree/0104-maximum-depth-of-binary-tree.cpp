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
    int maxDepth(TreeNode* root) {
        
        //Base Case
        if(root == NULL){
            return 0;
        }

        //recursive call
        int leftDepth = maxDepth(root -> left);
        int rightDepth = maxDepth(root -> right);
        
        //return the result
        return (1+ max(leftDepth, rightDepth));
    }
};