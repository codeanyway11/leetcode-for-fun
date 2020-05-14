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
    void getMinDiff(TreeNode* root, int* minDiff, int *last){
        if(!root) return;
        getMinDiff(root->left, minDiff, last);
        *minDiff = *last == INT_MAX? *minDiff: min(root->val - *last, *minDiff);
        *last = root->val;
        getMinDiff(root->right, minDiff, last);
        return;
    }
    
    
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int last = INT_MAX;
        getMinDiff(root, &minDiff, &last);
        return minDiff == INT_MAX? 0: minDiff;
        
    }
};