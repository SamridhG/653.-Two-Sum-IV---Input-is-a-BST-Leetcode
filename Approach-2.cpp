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
    vector<int>A;
    void inorder(TreeNode *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            A.push_back(root->val);
            inorder(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        unordered_set<int>B;
        for(int i=0;i<A.size();i++)
        {
            if(B.find(k-A[i])!=B.end())
            {
                return true;
            }
            else
            {
                B.insert(A[i]);
            }
        }
        return false;
        
    }
};
