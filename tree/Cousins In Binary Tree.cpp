// Question: https://leetcode.com/problems/cousins-in-binary-tree/
// Question: https://leetcode.com/problems/cousins-in-binary-tree/

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
	void mapDepths(int depth, TreeNode* root, vector<vector<TreeNode*> > &matrix, int x, int *actualDepth){
		if(root == NULL){
			return;
		}
		matrix[depth].push_back(root);

		// The reason I am returning here is because I don't want to push the sibling in the matrix.
		if(root->left && root->left->val == x){
			*actualDepth = depth+1;
    		return;
    	}

		// The reason I am returning here is because I don't want to push the sibling in the matrix.
    	if(root->right && root->right->val == x){
    		*actualDepth = depth+1;
    		return;
    	}
        mapDepths(depth + 1, root->left, matrix, x, actualDepth);
    	mapDepths(depth + 1, root->right, matrix, x, actualDepth);
    	
	}


    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL || root->val == x || x==y){
            return false;
        }
        // std::vector<std::vector<int>> matrix(M, std::vector<int>(N, default_value));

        vector<vector<TreeNode*> > matrix(100, vector<TreeNode*>());

        int depth = 0;
        int actualDepth = -1;

        mapDepths(depth, root, matrix, x, &actualDepth);

        vector<TreeNode*> newVector = matrix[actualDepth];
        for(int i=0; i<newVector.size(); i++){
        	if(newVector[i]!= NULL && newVector[i]->val == y){
        		return true;
        	}
        }
        
        return false;
    }
};