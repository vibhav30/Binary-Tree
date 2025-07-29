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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        map<pair<int,int>,multiset<int>> mp;
        int depth=-1;
        q.push({root,0});
        while(!q.empty())
        {
            int sz=q.size();
            depth++;
            while(sz--)
            {
              TreeNode* node=q.front().first;
              int y=q.front().second;
              q.pop();
              mp[{y,depth}].insert(node->val);
              if(node->left) q.push({node->left, y-1});
              if(node->right) q.push({node->right, y+1});
            }
        }
        vector<vector<int>> v;
        vector<int> t;
        int yt=INT_MIN;
        for(auto it : mp)
        {
          int y=it.first.first;
          if(y>yt)
          {
            if (!t.empty()) v.push_back(t);
            t.clear(); yt=y;
          }
          for(int it2 : it.second)
          {
            t.push_back(it2);
          }
        }
        if (!t.empty()) v.push_back(t);
        return v;
    }
};
