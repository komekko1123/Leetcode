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
    TreeNode* deleteNode(TreeNode* root, int key) { //刪除跟比較麻煩
      if( root == NULL )
        return NULL;
      if( root->val > key)
        root->left = deleteNode(root->left, key);
      else if( root->val < key)
        root->right = deleteNode(root->right, key);
      else{
        if( root->left == NULL && root->right == NULL){ // CASE 1 沒有子節點
          return NULL;
        } // if

        else if( root->left != NULL && root->right == NULL){ //case2有左子，就把左子題上來
          return root->left;
        } // else if

        else if( root->left == NULL && root->right != NULL){ //case3 有右子，就把右子題上來
          return root->right;
        } // else if

        else {   // else if ( root->left != NULL && root->right != NULL) // case 4
          TreeNode* current = root, *temp = root->left; // 拿左子樹的最右邊節點交換 or 右子的最左邊節點換
          while( temp->right != NULL){
            current = temp;
            temp = temp ->right;
          }// while

          if( current != root){
            root->val = temp ->val;
            current->right = temp->left;
            temp->left = NULL;
            delete temp;
          } // if
          else{
            root->val = temp ->val;
            root->left = temp ->left; 
            temp->left = NULL;
            delete temp;
          } // if 
        } // else 
      } // else

      return root;
    }

};
