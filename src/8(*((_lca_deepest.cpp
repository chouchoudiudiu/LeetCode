http://www.1point3acres.com/bbs/thread-199739-1-1.html
/*
给一个 二叉树 ， 求最深节点的最小公共父节点。
     1.
  2   3
     5  6    return 3.

       1  
    2   3
4      5 6   retrun 1.
*/

TreeNode* dfs(TreeNode* root, int & depth){
    if(!root){
        depth = 0;
        return NULL;
    }
    
    int ldepth, rdepth;
    TreeNode * left = dfs(root->left, ldepth);
    TreeNode * right = dfs(root->right, rdepth);
    depth = 1 + max(ldepth, rdepth);
    
    if(ldepth == rdepth) return root;
    else if(ldepth < rdepth) return right;
    else return right;
}

int commonAncestor(TreeNode * root){
    int depth;
    TreeNode* LCA = dfs(root, depth);
    cout << "Tree depth:" << depth << endl;
    return LCA->val;
}
