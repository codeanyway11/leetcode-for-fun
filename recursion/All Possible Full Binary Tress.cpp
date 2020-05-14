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
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N%2 == 0) return {};
        if(N == 1) return vector<TreeNode*> ({new TreeNode(0)});
        vector<TreeNode*> ans;
        for(int i=1; i<N; i+=2){
            for(auto l : allPossibleFBT(i)){
                for(auto r: allPossibleFBT(N-i-1)){
                    TreeNode* newNode = new TreeNode(0);
                    newNode-> left = l;
                    newNode->right = r;
                    ans.push_back(newNode);
                }
            }
            
        }
        return ans;
    }
};