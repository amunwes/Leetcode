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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        check_level(root,0,result);
        return result;

    }
private:
    void check_level(TreeNode* root,int level,vector<int> &result){
        if (root == NULL){
            return;
        }
        if (level == result.size()){
            result.push_back(root->val);
        }
        check_level(root->right, level+1, result);
        check_level(root->left, level+1, result);
    }
};