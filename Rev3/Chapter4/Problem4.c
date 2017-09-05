/*
 * Check if a binary tree is balanced
 */

/*Get the height of the tree */
int height(struct node* root) {
    if(root==NULL) return 0;
    else {
        int lh = height(root->left);
        int rh = height(root->right);
        return((lh>=rh)?(lh+1):(rh+1));
    }
}

bool isBalanced(struct node* root) {
    if(root==NULL) return true;
    else {
        int lh = height(root->left);
        int rh = height(root->right);

        return(abs(lh-rh)<=1 && isBalanced(root->left)
                             && isBalanced(root->right));
    }
}
