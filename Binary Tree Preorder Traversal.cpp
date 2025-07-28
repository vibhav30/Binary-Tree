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
       ans.push_back(node->val);
       if(node->left) reccursive(node->left, ans);
       if(node->right) reccursive(node->right, ans); 
    }

    void iterative(TreeNode* node, vector<int>& ans)
    {
        stack<TreeNode*> st;
        if(node) st.push(node);
        while(!st.empty())
        {
            TreeNode* nd=st.top(); st.pop();
            ans.push_back(nd->val); 
            if(nd->right) st.push(nd->right);
            if(nd->left) st.push(nd->left);
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
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    prev->right=nullptr;
                    curr=curr->right;
                }
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        //reccursive(root, ans);
        //iterative(root, ans);
        morris(root, ans);
        return ans;
    }
};
