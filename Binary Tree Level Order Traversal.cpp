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
    void bfs(TreeNode* root, vector<vector<int>>& v)
    {
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz=q.size();
            vector<int> temp;
            while(sz--)
            {
              TreeNode* node=q.front(); q.pop();
              temp.push_back(node->val);
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
            }
            v.push_back(temp);
        }
    }

    void dfs(TreeNode* node, int depth, vector<vector<int>>& v)
    {
       if(!node) return;
       if(depth==v.size()) v.push_back({});
       v[depth].push_back(node->val);
       dfs(node->left,depth+1,v);
       dfs(node->right,depth+1,v);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        //bfs(root, v);
        dfs(root,0,v);
        return v;
    }
};
