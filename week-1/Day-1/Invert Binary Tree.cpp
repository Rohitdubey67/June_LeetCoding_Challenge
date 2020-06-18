/*
invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*/

/*
Time: O(N)
Space: O(N) because of recursive call
concept: DFS
*/

TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)
            return root;
            
        //do recursive call left subtree
        TreeNode*l=invertTree(root->left);
        
        ////do recursive call right subtree
        TreeNode*r=invertTree(root->right);
        
        //change the address of left child with right child
        root->left=r;
        
        //change the address of right child with left child
        root->right=l;
        return root;
    }
   
