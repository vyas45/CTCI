/*
 * Check if a binary tree is a BST
 */
bool isBST(struct node* root) {
    static struct node* prev = NULL;
    if(root) {
        if(!isBST(root->left))
            return false;
        if(prev!=NULL && prev->data > root->data)
            return false;
        return(isBST(root->right));
    } 
    return true;
}
