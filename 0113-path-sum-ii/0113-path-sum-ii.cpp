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
    vector<int> temp;
    vector<vector<int>> result;

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        DFS(root, targetSum);

        return result;
    }

    void DFS(TreeNode* now, int targetSum)
    {
        if(now == nullptr)
        {
            return;
        }

        temp.push_back(now -> val);

        if((now->left == nullptr) && (now->right == nullptr) && (now->val == targetSum))
        {
            result.push_back(temp);
        }

        DFS(now -> left, targetSum - (now -> val));
        DFS(now -> right, targetSum - (now -> val));

        temp.pop_back();


    }
};