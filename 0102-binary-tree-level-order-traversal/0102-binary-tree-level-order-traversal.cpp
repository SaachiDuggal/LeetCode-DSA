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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        //edge cases
        if(root == NULL){
            return {};
        }

        //initialising result
        vector<vector<int>> result;

        //initialising a queue for processing the nodes level by level
        queue<TreeNode*> q;

        //we add the node to the queue
        q.push(root);

        //run a while loop, till the queue is not empty,
        while(!q.empty()){
            //we first note the queue size
            int level_size = q.size();

            //initialise a current_level array
            vector<int> current_level;

            //then we run a loop till we hit the queue size
            for(int i = 0; i < level_size; i++){
                //initialise a node at the front of the queue then pop it and add it to current_level
                TreeNode* node = q.front();
                q.pop();
                current_level.push_back(node -> val);

                //if the node has children, add them to the queue
                if(node -> left)q.push(node -> left);
                if(node -> right)q.push(node -> right);
            }
            //pushback the current level in the result
            result.push_back(current_level);
        }
        return result;
    }
};