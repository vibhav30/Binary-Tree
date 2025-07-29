/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		vector<vector<int> > treeTraversal(TreeNode* root){
		    vector<int> in, pre, post;
		    vector<vector<int>> ans;
		    stack<pair<TreeNode*,int>> st;
		    if(root) st.push({root,1});
		    while(!st.empty())
		    {
		       TreeNode* node=st.top().first; 
		       int num=st.top().second;
		       st.pop();
		       if(num==1)
		       {
			pre.push_back(node->data);
			st.push({node, num+1});
			if(node->left) st.push({node->left,1});
		       }
		       if(num==2)
		       {
			in.push_back(node->data);
			st.push({node, num+1});
			if(node->right) st.push({node->right,1});
		       }
		       if(num==3)
		       {
			post.push_back(node->data);
		       }
	
		    }
		    ans={in, pre, post};
		    return ans;
		}
};
