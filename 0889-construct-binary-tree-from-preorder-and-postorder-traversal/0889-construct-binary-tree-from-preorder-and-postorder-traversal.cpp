/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recur(int preStart, int preEnd, int postStart, vector<int>& preorder, unordered_map<int, int>& postorderIDX) {
        if (preStart > preEnd) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) {
            return root;
        }
        int Lroot = preorder[preStart + 1];
        int numLnodes = postorderIDX[Lroot] - postStart + 1;
        root->left = recur(preStart + 1, preStart + numLnodes, postStart, preorder, postorderIDX);
        root->right = recur(preStart + 1 + numLnodes, preEnd, postStart + numLnodes, preorder, postorderIDX);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        unordered_map<int, int> postorderIDX;
        for (int i = 0; i < preorder.size(); i++) {
            postorderIDX[postorder[i]] = i;
        }
        return recur(0, preorder.size() - 1, 0, preorder, postorderIDX);
    }
};