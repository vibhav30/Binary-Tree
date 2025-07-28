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
       reccursive(node->right, ans);
       ans.push_back(node->val);
    }

    void iterative2stack(TreeNode* node, vector<int>& ans)
    {
        stack<TreeNode*> st1, st2;
        if(node) st1.push(node);
        while(!st1.empty())
        {
            TreeNode* curr=st1.top(); st1.pop();
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
        }
        while(!st2.empty())
        {
            ans.push_back(st2.top()->val); st2.pop();
        }
    }

    void iterative1stack(TreeNode* node, vector<int>& ans)
    {
        stack<TreeNode*> st;
        TreeNode* curr=node;
        while(curr || !st.empty())
        {
            if(curr) 
            {
                st.push(curr);
                curr=curr->left;
            }
            else
            {
                TreeNode* temp=st.top()->right;
                if(!temp)
                {
                   temp=st.top(); st.pop();
                   ans.push_back(temp->val);
                   while(!st.empty() && temp==st.top()->right)
                   {
                    temp=st.top(); st.pop();
                    ans.push_back(temp->val);
                   }

                }
                else curr=temp;
            }
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        //reccursive(root, ans);
        //iterative2stack(root, ans);
        iterative1stack(root, ans);
        return ans;
    }
};
