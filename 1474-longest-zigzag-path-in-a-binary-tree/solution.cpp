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
    int ans = 0;
    int longestZigZag(TreeNode* root) {
      if( root == NULL)
        return 0;
      dfs(root,1,0);
      dfs(root,2,0);
      return ans;   
    }

    void dfs(TreeNode* root,int val, int len) {
      if( root == NULL)
        return;
      ans = max(len,ans);
      if( val == 1){ // 1是現在是左，要往右
        dfs(root->right,2,1+len); 
        dfs(root->left,1,1);
      } // else if
      
      else{ // 2是右要往左子
        dfs(root->left,1,1+len);
        dfs(root->right,2,1); 
      }
    }
};
