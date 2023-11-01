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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        unordered_map<int, int> freq; 
        int maxi = 0; 

        for(int val: res)
        {
            freq[val]++;
            maxi = max(maxi, freq[val]);
        }

        vector<int> result;
        for(const auto&pair : freq)
        {
            if(pair.second==maxi)
            {
                result.push_back(pair.first);
            }
        }
        return result;
    }
private: 
    void inorder(TreeNode* root, vector<int>& res)
    {
        if(!root) 
        {
            return;
        }
        res.push_back(root->val);
        inorder(root->left, res);
        inorder(root->right, res);
    }
};
