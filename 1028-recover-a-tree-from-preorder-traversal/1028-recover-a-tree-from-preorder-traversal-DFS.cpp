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
    int dashes(int idx, string& traversal) {
        int count = 0;
        while (idx < traversal.length() && traversal[idx] == '-') {
            count++;
            idx++;
        }
        return count;
    }

    int num(int &idx, string& traversal) {
        int res = 0;
        while (idx < traversal.length() && isdigit(traversal[idx])) {
            res = res * 10 + (traversal[idx] - '0');
            idx++;
        }
        return res;
    }

    TreeNode* helper(string& traversal, int& idx, int depth) {
        if (idx >= traversal.length())
            return nullptr;
        int dashCount = dashes(idx, traversal);
        if (dashCount != depth)
            return nullptr;
        idx += dashCount;
        int val = num(idx, traversal);
        TreeNode* node = new TreeNode(val);
        node->left = helper(traversal, idx, depth + 1);
        node->right = helper(traversal, idx, depth + 1);
        return node;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int idx = 0;
        return helper(traversal, idx, 0);
    }
};