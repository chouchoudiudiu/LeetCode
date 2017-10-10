http://www.1point3acres.com/bbs/thread-199739-1-1.html
/*
给一个 二叉树 ， 求最深节点的最小公共父节点。
     1.
  2   3
     5  6    return 3.

       1  
    2   3
4      5 6   retrun 1.
recursive 直接DFS找最底层最左和最右边的点然后求这两个点的LCA即可，iteration就变成BFS找最后一层的第一个和最后一个，找出点后求LCA即可
*/

TreeNode* dfs(TreeNode* root, int & depth){
    if(!root){
        depth = 0;
        return NULL;
    }
    
    int ldepth, rdepth;
    TreeNode* left = dfs(root->left, ldepth);
    TreeNode* right = dfs(root->right, rdepth);
    depth = 1 + max(ldepth, rdepth);
    
    if(ldepth == rdepth) 
      return root;
    else if(ldepth < rdepth) 
      return right;
    else 
      return left;
}

int commonAncestor(TreeNode * root){
    int depth;
    TreeNode* LCA = dfs(root, depth);
    cout << "Tree depth:" << depth << endl;
    return LCA->val;
}


 #include<iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


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
    else return left;
}

int commonAncestor(TreeNode * root){
    int depth;
    TreeNode* LCA = dfs(root, depth);
    cout << "Tree depth:" << depth << endl;
    return LCA->val;
}

int main() {
    TreeNode* A = new TreeNode(1);
    TreeNode* B = new TreeNode(2);
    TreeNode* C = new TreeNode(3);
    TreeNode* D = new TreeNode(4);
    TreeNode* E = new TreeNode(5);
    TreeNode* F = new TreeNode(6);
    TreeNode* H = new TreeNode(11);
    TreeNode* I = new TreeNode(17);
    A->left = B;
    A->right = C;
    C->left = E;
    C->right = F;
    B->left = D;
    F->right = H;
    
    E->left = I;
    cout<<commonAncestor(A)<<endl;;
    
    return 0;
    
}
