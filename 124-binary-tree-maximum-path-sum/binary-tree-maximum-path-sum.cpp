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
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        helper(root, result);
        return result;
    }

private:
    int helper(TreeNode* root, int& result){
        if(root == NULL){
            return 0;
        }

        int right= max(helper(root->right, result),0);
        int left = max(helper(root->left, result),0);

        int currPath = right + left + root->val;
        result = max(result, currPath);
        
        return root->val + max(left, right);
    }
};