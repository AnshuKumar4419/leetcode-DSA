/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 0;
        while(q.size() > 0) {
            int size = q.size();
            vector<int> row(size);
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index = 0;
                if(flag == 0) {
                    index = i;
                } 
                else {
                    index = size - i - 1;
                }
                row[index] = node->val;
                if(node->left != NULL) {
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    q.push(node->right);
                }
            }
            if(flag == 0) flag = 1;
            else flag = 0;
            ans.push_back(row);
        }
        return ans;
    }
};