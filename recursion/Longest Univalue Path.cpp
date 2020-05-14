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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        if(!root){
            return 0;
        }
        longestSub(root, &ans);
        return ans;
        
    }
    
    int longestSub(TreeNode* root, int *ans){
        int l = root->left? longestSub(root->left, ans): 0;
        int r = root->right? longestSub(root->right, ans):0;
        int rightAns = root->right && root->val == root->right->val? r+1 : 0;
        int leftAns = root->left && root->val == root->left->val? l+1 : 0;
        *ans = max(*ans, leftAns+rightAns);
        return max(leftAns, rightAns);
        
    }
    
    
};