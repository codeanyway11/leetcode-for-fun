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
    void calculateSum(TreeNode* root, int L, int R, int* sum){
        if(root == NULL){
            return;
        }
        
        if(root->val >=L && root->val <= R){
            *sum += root->val;
        }
        
        calculateSum(root->left, L, R, sum);
        calculateSum(root->right, L, R, sum);
        return;
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        calculateSum(root, L, R, &sum);
        return sum;
        
    }
};