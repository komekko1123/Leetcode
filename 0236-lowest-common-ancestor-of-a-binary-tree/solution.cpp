/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool find_one = false; // 找的一個後可以往下或做backtracking
    TreeNode * ans = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) 
          return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left != NULL && right != NULL) 
          return root;
        if(left != NULL)
          return left;
        else
          return right;
    //   if(root->left == NULL && root->right == NULL)
    //     return root;  
    //   dfs(root,p->val, q->val);
    //   return ans;
    }

    TreeNode* dfs( TreeNode* root, int val1, int val2 ){  // 如果找到的話，往下找看看有沒有
      if( root == NULL)
        return NULL;
      TreeNode *left,*right;
      left = dfs(root->left,val1,val2);
      right = dfs(root->right,val1,val2);


      if( (root-> val == val1 || root->val == val2) && find_one == false){
        find_one = true;
        return root;         
      } // if


      else if( left != NULL && right != NULL && find_one == true ){
        ans = root; // 找到parent
        cout << ans->val ;
        find_one = false;
        return NULL;
      } // else if


      else if( (root-> val == val1 || root->val == val2) && ( left != NULL || right != NULL ) && find_one == true ){ //代表著是重複
        ans = root;
        find_one = false;
        return root;
      } // else if

      else if( (root-> val == val1 || root->val == val2) && ( left == NULL || right == NULL ) && find_one == true ){
        return root;
      } // else if

      
      if( left != NULL )
        return left;
      else if( right != NULL)
        return right;
      else
        return NULL;
    } // dfs;

};
