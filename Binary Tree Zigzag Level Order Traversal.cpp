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
    void bfsRev(TreeNode* root, vector<vector<int>>& v)
    {
        queue<TreeNode*> q;
        if(root) q.push(root);
        int flag=0;
        while(!q.empty())
        {
           int sz=q.size();
           vector<int> t;
           while(sz--)
           {
              TreeNode* node=q.front(); q.pop();
              t.push_back(node->val);
              if(node->left) q.push(node->left);
              if(node->right) q.push(node->right);
           }
           if(flag) reverse(t.begin(), t.end());
           v.push_back(t); flag^=1;
        }
    }

    void bfsDeque(TreeNode* root, vector<vector<int>>& v)
    {
        if (!root) return;
        deque<TreeNode*> dq;
        dq.push_back(root);
        int flag = 0;
        while (!dq.empty())
        {
            int sz = dq.size();
            vector<int> level;
            while(sz--)
            {
                if(flag)
                {
                   TreeNode* node = dq.back(); dq.pop_back();
                   level.push_back(node->val);
                   if (node->right) dq.push_front(node->right);
                   if (node->left) dq.push_front(node->left);
                }
                else
                {
                   TreeNode* node = dq.front(); dq.pop_front();
                   level.push_back(node->val);
                   if (node->left) dq.push_back(node->left);
                   if (node->right) dq.push_back(node->right);
                }
            }
            v.push_back(level);
            flag ^= 1;
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        //bfsRev(root,v);
        bfsDeque(root, v); 
        return v;
    }
};
