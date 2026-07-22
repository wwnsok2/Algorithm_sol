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
    int maxDepth(TreeNode* root) {
        return dfs(root,0);

    }

    int dfs(TreeNode* root, int depth)
    {
        if(root == nullptr)
        {
            return depth;
        }

        depth += 1;

        int d_right = dfs(root->right, depth);
        int d_left = dfs(root->left, depth);
        int max_depth = d_left > d_right ? d_left : d_right;


        return max_depth;
    }
};