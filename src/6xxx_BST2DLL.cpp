#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : val(value), left(NULL), right(NULL) {}
};

void BST2DLL(TreeNode* p, TreeNode*& prev, TreeNode*& head) {
    if(!p)
        return;
    BST2DLL(p->left, prev, head);
    p->left = prev;
    if(prev)
        prev->right = p;
    else
        head = p;
    TreeNode* right = p->right;
    head->left = p;
    p->right = head;
    
    prev = p; //inorder
    BST2DLL(right, prev, head);
}


int main()
{
    TreeNode* root = new TreeNode(4);
    TreeNode* A = new TreeNode(2);
    TreeNode* B = new TreeNode(5);
    TreeNode* C = new TreeNode(1);
    TreeNode* D = new TreeNode(3);

    root->left = A;
    root->right = B;
    A->left = C;
    A->right = D;

    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;

    BST2DLL(root, prev, head);
    TreeNode* p = head;

    cout<<"hello"<<endl;
    printf("%d->", p->val);
    p = p->left;
    printf("%d->", p->val);
    p = p->left;
    printf("%d->", p->val);
    p = p->left;
    printf("%d->", p->val);
    p = p->left;
    printf("%d->", p->val);
    p = p->left;
    printf("%d->", p->val);
    
    return 0;

}


// This is a modified in-order traversal adapted to this problem.
// prev (init to NULL) is used to keep track of previously traversed node.
// head pointer is updated with the list's head as recursion ends.
