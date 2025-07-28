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
    void reccursive(TreeNode* node, vector<int>& ans)
    {
        if(!node) return;
        reccursive(node->left, ans);
        ans.push_back(node->val);
        reccursive(node->right, ans);
    }

    void iterative(TreeNode* node, vector<int>& ans)
    {
        stack<TreeNode*> st;
        TreeNode* curr=node;
        while(curr || !st.empty())
        {
            while(curr)
            {
                st.push(curr);
                curr=curr->left;
            }
            curr=st.top(); st.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        } 
    }

    void morris(TreeNode* node, vector<int>& ans)
    {
        TreeNode* curr=node;
        while(curr)
        {
            if(!curr->left)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(!prev->right)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    prev->right=nullptr;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        //reccursive(root,ans);
        //iterative(root, ans);
        morris(root, ans);
        return ans;
    }
};
