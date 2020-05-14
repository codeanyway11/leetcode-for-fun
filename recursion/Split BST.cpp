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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
       if(!root) return vector<TreeNode*> ({NULL, NULL});
        if(root->val <= V){
            vector<TreeNode*> ans = splitBST(root->right, V);
            root->right = ans[0];
            ans[0] = root;
            return ans;
        }else{
            vector<TreeNode*> ans = splitBST(root->left, V);
            root->left = ans[1];
            ans[1] = root;
            return ans;
        }
    }
};