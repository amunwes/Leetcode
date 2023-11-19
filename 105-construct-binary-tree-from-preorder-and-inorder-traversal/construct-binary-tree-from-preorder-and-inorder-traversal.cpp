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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size()-1);
    }

private:
    int find_index(vector<int>& inorder, int k){
        int index = (find(inorder.begin(), inorder.end(), k) - inorder.begin());  
        return index;
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& preindex, int instart, int inend){
        if(instart > inend){
            return NULL;
        }

        int val = preorder[preindex++];
        TreeNode* node = new TreeNode(val);// uses then increments so will start with 0
        int inindex = find_index(inorder, val);

        node->left = build(preorder, inorder, preindex, instart, inindex - 1);
        node->right = build(preorder, inorder, preindex, inindex + 1, inend);
        return node;
        
    }

};